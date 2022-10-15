fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val a = IntArray(n)
        a[0] = if (n <= 3) n else n - 1
        a[a.size - 1] = if (n <= 2 ) 1 else 2
        var s = (n - 1) * 1L * (n - 1)
        repeat((n - 2) / 2){
            a[n - 2 - it] = n - 2 - it
            s += (n - 2 - it).let { it * 1L * it }
            if (it + 1 == (n - 2) / 2) a[n - 2 - it] = n
        }
        repeat((n - 1) / 2){
            a[it + 1] = it + 3
            s += (n - it - 2).let { it * 1L * it }
            if (it + 1 == (n - 1) / 2) a[it + 1] = 1
        }
        println(s)
        println(a.joinToString(" "))
        println(n - 1)
        repeat((n - 2) / 2){
            println("${n - 1 - it} 1")
        }
        repeat((n - 1) / 2){
             println("${it + 2} $n")
        }
        println("1 $n")
    }
}