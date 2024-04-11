fun readLn() = readLine()!!
fun readStrings() = readLn().split(" ")
fun readInts() = readStrings().map { it.toInt() }
fun readLongs() = readStrings().map { it.toLong() }
 
const val MOD = 998244353
const val NBIT = 60
 
fun run() {
    val (na) = readInts()
    val a = readLongs()
    val nb = na-1
    
    fun suffixok(bit: Int, mask: Int): Boolean {
        var sum=0L
        for(i in 0 until na) sum = sum xor (a[i] shr bit)
        for(i in 0 until nb) sum = sum xor ((if(((mask shr i) and 1)==0) a[i] else a[i+1]) shr bit)
        return sum==0L
    }
    
    var ans=0
    for(mask in 0 until (1 shl nb)) { 
        if(suffixok(0,mask)) {
            var ways = 1
            for(i in 0 until nb) if(a[i+1]==a[i]&&((mask shr i) and 1)==1) ways = 0
            if(ways!=0) {
                //println("exact $mask ok")
                ans=(ans+ways)%MOD
            }
        }
        for(bit in 0 until NBIT) {
            if(!suffixok(bit+1,mask)) continue
            val dp = Array(nb+1,{Array(2,{IntArray(2){0}})}) // dp[i][sum][have]
            dp[0][0][0]=1
            for(i in 0..nb) for(sum in 0..1) for(have in 0..1) {
                val ways=dp[i][sum][have]
                if(ways==0) continue
                if(i==nb) break
                val side = (mask shr i) and 1
                val lhe = ((a[i] shr bit) and 1).toInt()
                val rhe = ((a[i+1] shr bit) and 1).toInt()
                val same = (a[i] shr (bit+1))==(a[i+1] shr (bit+1))
                for(me in 0..1) {
                    if((same||side==0)&&me<lhe||(same||side==1)&&me>rhe) continue
                    if(same&&lhe!=rhe&&side!=me) continue
                    if(same&&lhe==rhe&&side==1) continue
                    val nsum=sum xor me
                    val diff = side==0&&me>lhe||side==1&&me<rhe
                    val mlt: Long
                    if(diff) {
                        mlt=1L shl bit
                    } else if(same&&lhe==rhe) {
                        mlt=a[i+1]-a[i]+1
                    } else if(side==0) {
                        mlt=(((a[i] shr bit)+1) shl bit)-a[i]
                    } else {
                        mlt=a[i+1]-((a[i+1] shr bit) shl bit)+1
                    }
                    if(have==0&&diff) {
                        dp[i+1][nsum][1]=(dp[i+1][nsum][1]+ways)%MOD
                    } else {
                        dp[i+1][nsum][have]=((dp[i+1][nsum][have]+ways*(mlt%MOD))%MOD).toInt()
                    }
                }
            }
            var want = 0
            for(i in 0 until na) want=want xor ((a[i] shr bit) and 1).toInt()
            if(dp[nb][want][1]!=0) {
                //println("$mask $bit -> ${dp[nb][want][1]}")
                ans=(ans+dp[nb][want][1])%MOD
            }
        }
    }
    println(ans)
}
 
fun main() {
    run()
}