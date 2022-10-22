//val n = readLine()!!.toInt();
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    val n = readLine()!!.toInt();
    var v1 = readLine()!!.split(" ").map{it.toInt()}.toMutableList();
    var v2 = readLine()!!.split(" ").map{it.toInt()}.toMutableList();
    val m = readLine()!!.toInt();
    var v3 = readLine()!!.split(" ").map{it.toInt()}.toMutableList();
    v1.sort();
    v2.sort();
    var vb: MutableList<Pair<Int,Int>> = mutableListOf();
    for(i in 0 until m){
        vb.add(Pair(v3[i],i));
    }
    vb.sortBy { it.first };
    v3.sort();
    var va=IntArray(n);
    var vs=IntArray(m);
    for(i in n-1 downTo 0){
        val a=v2[i+1]-v1[i];
        if(i==n-1)va[i]=a;
        else va[i]=max(va[i+1],a);
    }
    var a=Int.MIN_VALUE;
    var id=0;
    for(i in 0 until n){
        val b=max(va[i],a);
        while(id<m && v3[id]<=v1[i]){
            val s=max(b,v2[i]-v3[id]);
            vs[vb[id].second]=s;
            id++;
        }
        a=max(a,v2[i]-v1[i]);
    }
    while(id<m){
        val s=max(a,v2.last()-v3[id]);
        vs[vb[id].second]=s;
        id++;
    }
    println(vs.joinToString(separator = " "));
}

fun main(){
    solve();
}