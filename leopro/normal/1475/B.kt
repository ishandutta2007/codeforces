fun main() {
    repeat(readLine()!!.toInt()){
        val n = readLine()!!.toInt()
        for (times in 0 until 2020){
            if ((n - times * 2020).let { it >= 0 && it % 2021 == 0 }) return@repeat println("YES")
        }
        println("NO")
    }
}