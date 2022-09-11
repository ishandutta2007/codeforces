fun main() {
    val (n,q)=readLine()!!.split(" ").map{it.toInt()}
    val a=readLine()!!.split(" ").map{it.toInt()}
    fun calc(lim: Int):Long {
        // L>=ceil(len/2) -> L-R-par>=0
        val v=List(n){if(a[it]<=lim) +1 else -1}
        val freqevn=MutableList(2*n+1){0}
        val freqodd=MutableList(2*n+1){0}
        var at=0;
        for(i in v.indices) { at+=v[i]; if(i%2==0) ++freqodd[n+at]; else ++freqevn[n+at]; }
        at=0;
        var sumevn=0; for(x in at..n) sumevn+=freqevn[n+x]
        var sumodd=0; for(x in at..n) sumodd+=freqodd[n+x]
        var ret=0L;
        ret+=sumevn+sumodd-freqodd[n+at]
        for(i in v.indices) {
            if(v[i]>0) repeat(v[i]) { sumevn-=freqevn[n+at]; sumodd-=freqodd[n+at]; ++at }
            if(v[i]<0) repeat(-v[i]) { --at; sumevn+=freqevn[n+at]; sumodd+=freqodd[n+at] }
            if(i%2==0) { --freqodd[n+at]; --sumodd; }
            if(i%2==1) { --freqevn[n+at]; --sumevn; }
            if(i%2==0) ret+=sumevn+sumodd-freqevn[n+at]
            if(i%2==1) ret+=sumevn+sumodd-freqodd[n+at]
        }
        return ret
    }
    println(calc(q)-calc(q-1))
}