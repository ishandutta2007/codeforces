//var list= readLine()!!.split(" ").map(String::toInt)

fun main(){
    val n= readLine()!!.toInt()
    for(i in 1..n){
        val a = readLine()!!.toInt()
        println((a-1)/2)
    }
}