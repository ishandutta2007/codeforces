/*
    author:  Maksim1744
    created: 07.10.2021 19:21:09
*/

fun add(a: Long, b: Long): Long {
    var res = a + b
    if (res >= 998244353.toLong()) {
        res -= 998244353.toLong()
    }
    return res
}

fun sub(a: Long, b: Long): Long {
    var res = a - b
    if (res < 0.toLong()) {
        res += 998244353
    }
    return res
}

fun mul(a: Long, b: Long): Long {
    return a * b % 998244353.toLong()
}

fun pw(aa: Long, bb: Long): Long {
    var a = aa
    var b = bb
    var res = 1.toLong()
    while (b != 0.toLong()) {
        if (b % 2 == 1.toLong()) {
            res = mul(res, a)
        }
        a = mul(a, a)
        b /= 2
    }
    return res
}

fun inv(a: Long): Long {
    return pw(a, 998244353 - 2)
}

fun main() {
    var (n, a, b) = readLine()!!.split(' ').map{ it.toInt() }
    var prob1 = HashMap<Int, Long>()
    var prob2 = HashMap<Int, Long>()
    var i100 = inv(1000000.toLong())

    var xl = ArrayList<Int>()
    var yl = ArrayList<Int>()
    xl.add(0)
    xl.add(a)
    yl.add(0)
    yl.add(b)

    for (i in 0..n-1) {
        var (x, y, pp) = readLine()!!.split(' ').map{ it.toInt() }
        var p = mul(i100, pp.toLong())
        xl.add(x);
        yl.add(y);
        run {
            var curp = prob1.getOrElse(y - x, {0.toLong()})
            var res = sub(1, mul(sub(1, curp), sub(1, p)))
            prob1[y - x] = res
        }
        run {
            var curp = prob2.getOrElse(y + x, {0.toLong()})
            var res = sub(1, mul(sub(1, curp), sub(1, p)))
            prob2[y + x] = res
        }
    }

    run {
        xl.sort()
        var x = ArrayList<Int>()
        for (k in xl) {
            if (x.size == 0 || x[x.size-1] != k) {
                x.add(k)
            }
        }
        xl = x
    }
    run {
        yl.sort()
        var x = ArrayList<Int>()
        for (k in yl) {
            if (x.size == 0 || x[x.size-1] != k) {
                x.add(k)
            }
        }
        yl = x
    }

    var ans = 0.toLong()

    for (ix in 0..xl.size-2) {
        for (iy in 0..yl.size-2) {
            var lx = xl[ix]
            var rx = xl[ix + 1]
            var ly = yl[iy]
            var ry = yl[iy + 1]
            // between
            run {
                for ((down, pdown) in prob1) {
                    if (lx + down >= ry) {
                        continue
                    }
                    if (rx + down <= ly) {
                        continue
                    }
                    for ((up, pup) in prob1) {
                        if (up <= down) {
                            continue
                        }
                        if (lx + up >= ry) {
                            continue
                        }
                        if (rx + up <= ly) {
                            continue
                        }
                        var curp = mul(pdown, pup)
                        for ((mid, pmid) in prob1) {
                            if (down < mid && mid < up) {
                                curp = mul(curp, sub(1, pmid))
                            }
                        }

                        var left: Int
                        var right: Int
                        if (lx + up <= ly) {
                            // x + up = ly
                            // (ly-up, ly)
                            left = ly * 2 - up
                        } else if (lx + down >= ly) {
                            // (lx, lx+down)
                            left = lx * 2 + down
                        } else {
                            left = lx + ly
                        }

                        if (rx + up <= ry) {
                            // (rx, rx+up)
                            right = rx * 2 + up
                        } else if (rx + down >= ry) {
                            // x+down = ry
                            // (ry-down, ry)
                            right = ry * 2 - down
                        } else {
                            right = rx + ry
                        }

                        var res = 1.toLong()

                        for ((mid, pmid) in prob2) {
                            if (left < mid && mid < right) {
                                res = add(res, pmid)
                            }
                        }

                        ans = add(ans, mul(res, curp))
                    }
                }
            }
            // single up
            run {
                for ((ddown, pdown) in prob1) {
                    if (lx + ddown >= ry) {
                        continue
                    }
                    if (rx + ddown <= ly) {
                        continue
                    }
                    var curp = pdown
                    for ((up, pup) in prob1) {
                        if (up >= ddown) {
                            continue
                        }
                        if (lx + up >= ry) {
                            continue
                        }
                        if (rx + up <= ly) {
                            continue
                        }
                        curp = mul(curp, sub(1, pup))
                    }

                    var left: Int
                    var right: Int

                    var up = ddown
                    var down = ly - rx

                    if (lx + up <= ly) {
                        // x + up = ly
                        // (ly-up, ly)
                        left = ly * 2 - up
                    } else if (lx + down >= ly) {
                        // (lx, lx+down)
                        left = lx * 2 + down
                    } else {
                        left = lx + ly
                    }

                    if (rx + up <= ry) {
                        // (rx, rx+up)
                        right = rx * 2 + up
                    } else if (rx + down >= ry) {
                        // x+down = ry
                        // (ry-down, ry)
                        right = ry * 2 - down
                    } else {
                        right = rx + ry
                    }

                    var res = 1.toLong()

                    for ((mid, pmid) in prob2) {
                        if (left < mid && mid < right) {
                            res = add(res, pmid)
                        }
                    }

                    ans = add(ans, mul(res, curp))
                }
            }
            // single down
            run {
                for ((ddown, pdown) in prob1) {
                    if (lx + ddown >= ry) {
                        continue
                    }
                    if (rx + ddown <= ly) {
                        continue
                    }
                    var curp = pdown
                    for ((up, pup) in prob1) {
                        if (up <= ddown) {
                            continue
                        }
                        if (lx + up >= ry) {
                            continue
                        }
                        if (rx + up <= ly) {
                            continue
                        }
                        curp = mul(curp, sub(1, pup))
                    }

                    var left: Int
                    var right: Int

                    var down = ddown
                    var up = ry - lx

                    if (lx + up <= ly) {
                        // x + up = ly
                        // (ly-up, ly)
                        left = ly * 2 - up
                    } else if (lx + down >= ly) {
                        // (lx, lx+down)
                        left = lx * 2 + down
                    } else {
                        left = lx + ly
                    }

                    if (rx + up <= ry) {
                        // (rx, rx+up)
                        right = rx * 2 + up
                    } else if (rx + down >= ry) {
                        // x+down = ry
                        // (ry-down, ry)
                        right = ry * 2 - down
                    } else {
                        right = rx + ry
                    }

                    var res = 1.toLong()

                    for ((mid, pmid) in prob2) {
                        if (left < mid && mid < right) {
                            res = add(res, pmid)
                        }
                    }

                    ans = add(ans, mul(res, curp))
                }
            }
            // none
            run {
                var curp = 1.toLong()
                for ((up, pup) in prob1) {
                    if (lx + up >= ry) {
                        continue
                    }
                    if (rx + up <= ly) {
                        continue
                    }
                    curp = mul(curp, sub(1, pup))
                }

                var res = 1.toLong()

                for ((mid, pmid) in prob2) {
                    if (mid > lx + ly && mid < rx + ry) {
                        res = add(res, pmid)
                    }
                }

                ans = add(ans, mul(res, curp))
            }
        }
    }

    println(ans)
}

/*

read array: readLine()!!.split(' ').map{ it.toInt() }.toMutableList()

var mp = HashMap<Int, Int>();
mp.getValue(k)
if (mp.contains(k))
mp.put(a, b)

val s = StringBuilder("test");
s[0] = 'g';
s.append(s);
println(s); // gestgest



credits: aleks5d

    
   )))

:
kotlinc A.kt -include-runtime -d A.jar
java -jar A.jar

  :
Pair<T1, T2> - 
Pair(a, b) -  
     - 

  (  ?)     
    !

    , ?
 : arr.sort()
  /    
arr.sortWith(compareBy({it.first}, {it.second}))  arr.sortWith(compareBy({it[0]}, {it[1]}))   

   
  ArrayList
ArrayList<Int>()
push_back = add
pop_back = removeAt(lastIndex)
arrayListOf()
list.binarySearch()

HashMap<String,Int>()

PriorityQueue<Pair<Long,Int>>({x,y ->
    x.first.compareTo(y.first)})

var A = arrayListOf(Pair(1,3),Pair(2,2),Pair(3,1))
val B = A.sortedWith(Comparator<Pair<Int,Int>>{x,y ->
    x.second.compareTo(y.second)})

             )))
*/