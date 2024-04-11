fun main() {
    val (n,m)=readLine()!!.split(" ").map{it.toInt()}
    val a=readLine()!!.split(" ").map{it.toInt()}
    val p=List(n){it}.sortedBy{a[it]}
    var ans=MutableList(n){0}
    var at=0;
    for(i in p) { while(a[p[at]]<a[i]) ++at; ans[i]=at; }
    repeat(m) {
        val (u,v)=readLine()!!.split(" ").map{it.toInt()-1}
        if(a[u]>a[v]) --ans[u]
        if(a[v]>a[u]) --ans[v]
    }
    println(ans.joinToString(" "))
}