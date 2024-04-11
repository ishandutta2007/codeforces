//val n = readLine()!!.toInt()
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun solve() {
    val INF:Long=1e9.toLong();
    var n = readLine()!!.toInt();
    val lst = readLine()!!.split(" ").map { it.toLong() };
    var m = readLine()!!.toInt();
    var v1 = ArrayList<Triple<Int, Int, Int>>();
    var vs = LongArray(m);
    for (i in 0..m - 1) {
        var (a, b) = readLine()!!.split(" ").map { it.toInt() };
        a-=2;b--;
        v1.add(Triple(a, b, i));
    }
    v1.sortBy({ it.second });
    var id = 0;
    var v2=ArrayList<Triple<Int,Long,Long>>();
    v2.add(Triple(-1,INF,0L));
    for(i in 0..n-1){
        while(!v2.isEmpty() && v2.last().second<=lst[i]) {
            v2.removeAt(v2.size - 1);
        }
        var su:Long=v2.last().third+lst[i]*(i-v2.last().first);
        v2.add(Triple(i,lst[i],su));
        while(id<v1.size && v1[id].second==i){
            var l=0;
            var r=v2.size-1;
            while(r-l>1){
                var mid=(l+r)/2;
                if(v1[id].first<v2[mid].first)r=mid;
                else l=mid;
            }
            var s:Long=v2[r].third-v2[r].second*(v2[r].first-v1[id].first);
            vs[v1[id].third]=su-s;
            id++;
        }
    }
    println(vs.joinToString(" "));
}

fun main(){
    solve();
}