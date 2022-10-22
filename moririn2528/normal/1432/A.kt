fun main(){
    val n= readLine()!!.toInt()
    for(i in 1..n){
        var list= readLine()!!.split(" ").map(String::toInt)
        println(list[0]+list[1])
    }
}