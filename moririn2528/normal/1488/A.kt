//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve(){
    val (x,y) = readLine()!!.split(" ").map{it.toInt()}
    var a:Int;
    var s=0;
    a=y/x;s=y%x;
    while(a>0){
        s+=a%10;
        a/=10;
    }
    println(s);
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 0..n-1){
        solve();
    }
}