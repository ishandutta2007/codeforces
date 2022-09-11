import kotlin.math.*


fun run() {
    val s=readLine()!!
    val n=s.length
    val z=IntArray(n+1)
    var start=0
    z[start]=-1
    var l=0; var r=0;
    val ret=CharArray(n); var at=0;
    var i=1;
    while(i<n) {
        var x = if(i<r) min(z[start+i-l],r-i) else 0
        while(i+x<n&&s[i+x]==s[start+x]) ++x
        z[i]=x
        if(i+x>r) { l=i; r=i+x; }
        
        if(i+x<n&&s[i+x]>s[start+x]) { ++i; continue }
        if(start+x>=i) {
            val period=i-start; val whole=1+x/period; val rem=x%period
            if(whole%2==1) {
                // put half of periods rounded up in A and remainder of string in B
                repeat((whole+1)/2) { repeat(period) { ret[at++]='R' } }
                while(at<n) ret[at++]='B'
                break
            } else {
                // put half of periods in A, half in B and continue with new start
                repeat(whole/2) { repeat(period) { ret[at++]='R' } }
                repeat(whole/2) { repeat(period) { ret[at++]='B' } }
                start+=whole*period; z[start]=-1; l=0; r=0; i=start+1;
            }
        } else {
            // put [start..i) in A and remainder of string in B
            repeat(i-start) { ret[at++]='R' }
            while(at<n) ret[at++]='B'
            break
        }
    }
    while(at<n) ret[at++]='R'
    println(String(ret))
}

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}