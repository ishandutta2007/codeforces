//val n = readLine()!!.toInt();
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    val sa = readLine()!!;
    val n=sa.length;
    var vs:MutableList<Int> = mutableListOf();
    var v0=IntArray(n+1);
    var v1=IntArray(n+1);
    for(i in 0 until n){
        v0[i+1]=v0[i];
        v1[i+1]=v1[i];
        if(sa[i]=='0')v0[i+1]++;
        else v1[i+1]++;
    }
    for(i in 1..n){
        var id=0;
        var s=0;
        while(id<n){
            if(n<=id+2*i){
                s++;
                break;
            }
            var l=id+2*i;
            var r=n+1;
            while(l+1<r){
                var m=(l+r)/2;
                if(v0[m]-v0[id]>i && v1[m]-v1[id]>i)r=m;
                else l=m;
            }
            s++;
            id=l;
        }
        vs.add(s);
    }
    println(vs.joinToString(separator = " "));
}

fun main(){
    solve();
}