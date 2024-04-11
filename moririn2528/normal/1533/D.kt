//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    val (n, m) = readLine()!!.split(" ").map { it.toInt() }.toMutableList();
    var s1: HashSet<String> = hashSetOf();
    for(i in 0 until n){
        val sa=readLine()!!;
        s1.add(sa);
    }
    val q = readLine()!!.toInt();
    for(i in 1..q){
        val sa= readLine()!!;
        var s=0;
        for(j in 0..m){
            if(j>0 && sa[j]==sa[j-1])continue;
            val sb=sa.removeRange(j,j+1);
            if(s1.contains(sb))s++;
        }
        println(s);
    }
}

fun main(){
    solve();
}