//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    val (n,m) = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
    val x: MutableList<Int> = MutableList(n) { it };
    var sa = readLine()!!;
    var a=0;
    var b=0;
    var s=0;
    for(ca in sa){
        if(ca=='1')b++;
    }
    if(b==0){
        println(0);
        return;
    }
    for(i in 0 until n){
        var pos=x[a];
        if(sa[pos]=='1')b--;
        if(b==0){
            println(i+1);
            return;
        }
        x.removeAt(a);
        a+=m-1;
        a%=x.size;
    }
    println(n);
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 1..n){
        solve();
    }
}