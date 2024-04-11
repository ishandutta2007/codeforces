fun main(){
    repeat(readLine()!!.toInt()){
        val (n, k) = readLine()!!.split(' ').map{ it.toInt() }
        val sum = (n + k - 1L) / k * k
        println((sum + n - 1) / n)
    }
}