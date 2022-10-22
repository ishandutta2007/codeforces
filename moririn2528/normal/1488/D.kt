//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve(){
    val (n,m) = readLine()!!.split(" ").map{it.toLong()};
    var l:Long = 0;
    var r:Long = m+10;
    while(r-l>1) {
        var mid: Long = (r + l) / 2;
        var cnt: Long = 0;
        for (i in 1..n) {
            if(mid==0L)break;
            cnt += mid;
            mid /= 2;
        }
        cnt += n;
        if (cnt <= m) l = (r + l) / 2;
        else r = (r + l) / 2;
    }
    println(l+1);
}

fun main(){
    var n = readLine()!!.toInt();
    for(i in 0..n-1){
        solve();
    }
}