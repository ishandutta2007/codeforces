fun main(){
    repeat(readLine()!!.toInt()) {
        readLine()
        val a = readLine()!!.split(' ').map { it.toInt() }
        val even = a.slice(0 until a.size step 2).sorted()
        val odd = a.slice(1 until a.size step 2).sorted()
        val able = (0 until a.lastIndex).all { i ->
            if (i % 2 == 0) even[i / 2] <= odd[i / 2]
            else odd[i / 2] <= even[i / 2 + 1]
        }
        println(if (able) "YES" else "NO")
    }
}