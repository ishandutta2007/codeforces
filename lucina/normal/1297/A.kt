fun readint()=readLine()!!.toInt()
fun readll()=readLine()!!.toLong()
fun readline_int()=(readLine()!!.split(" ").map{it.toInt()}).toIntArray()
fun readline_ll()=(readLine()!!.split(" ").map{it.toLong()}).toLongArray()



fun main () {
    var tt = readint() ;
    for (tttt in 0 until tt ) {
        var x = readll();
        if (x <= 999 ) {
            println(x)
            continue;
        }
        else if(x < 1000 * 1000) {
            var lb = (x / 1000 * 1000);
            var ub = lb + 1000 ;
            if (ub - x <= x - lb ) {
                if (ub == 1000L * 1000L) {
                    println("1M");
                }
                else println("${ub / 1000}K");
            }
            else println("${lb / 1000}K");
        }
        else {
            var lb = (x / 1000000 * 1000000);
            var ub = lb + 1000000 ;
            //println("${lb} ${ub}");
            if (ub - x <= x - lb ) {
                println("${ub / 1000000}M");
            }
            else println("${lb / 1000000}M");

        }
    }
 }