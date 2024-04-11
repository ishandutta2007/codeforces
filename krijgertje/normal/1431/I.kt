fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }

fun run() {
    val (h,w,nq) = readInts()
    val g = Array(h,{readLn()})
    
    val ord = Array(w+1, {IntArray(h)})
    for(x in 0 until h) ord[w][x]=x
    for(y in w-1 downTo 0) {
        val lst = Array(26,{mutableListOf<Int>()})
        for(x in ord[y+1]) lst[g[x][y]-'a'].add(x)
        var at = 0
        for(z in 0..lst.lastIndex) for(x in lst[z]) ord[y][at++]=x
        //println("$y: "+ord[y].joinToString(" "))
    }
    
    repeat(nq) {
        val s = readLn()
        //println("s=$s")
        var y=0
        var cnt=0
        while(y<w) {
            var best=0
            var lo=0
            var hi=h-1
            while(lo<=hi) {
                val mi=lo+(hi-lo)/2
                var cur=0
                while(y+cur<w&&s[y+cur]==g[ord[y][mi]][y+cur]) ++cur
                if(cur>best) best=cur
                if(y+cur>=w) break
                if(s[y+cur]<g[ord[y][mi]][y+cur]) hi=mi-1; else lo=mi+1
            }
            if(best==0) { cnt=-1; break }
            y+=best
            ++cnt
        }
        println(if(cnt==-1) -1 else cnt-1)
    }
}

fun main() {
    run()
}