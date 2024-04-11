fun run() {
    val s = readLine()!!
    val n = s.length
    val pref = s.scan(0){sum,c->sum+(if(c=='1') 1 else 0)}
    val one = pref.indices.filter{i->i==0||pref[i]!=pref[i-1]}
    val zero = pref.indices.filter{i->i==0||i-pref[i]!=i-1-pref[i-1]}
    println((1..n).map{k->
        var at=0
        var ans=0
        while(at<n) {
            val have1=pref[at]
            val to1=if(have1+k+1>=one.size) n else one[have1+k+1]-1
            val have0=at-pref[at]
            val to0=if(have0+k+1>=zero.size) n else zero[have0+k+1]-1
            val to=maxOf(to1,to0)
            ++ans
            at=to
        }
        ans
    }.joinToString(" "))
}

fun main() {
    run()
}