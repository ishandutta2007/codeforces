//var list= readLine()!!.split(" ").map(String::toInt)
import kotlin.math.*
fun solve(){
    val sa : String = readLine()!!
    var s :Int = 0;
    var a=0
    for(ca in sa){
        if(ca=='w'){
            s+=a/2+1
            a=0
        }else a++
    }
    s+=a/2
    println(s);
}

fun main(){
    val n = readLine()!!.toInt()
    for(i in 1..n){
        solve()
    }
}