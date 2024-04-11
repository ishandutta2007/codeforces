import kotlin.math.*

class Cartoon(var l:Int,var r:Int) {}

fun ok(x:Int):Boolean { return 0<=x&&x<=999 || x%1000==0&&1000<=x&&x<=999000 || x%1000000==0&&1000000<=x; }
fun format(x:Int):String { if(x<=999) return x.toString(); if(x<=999000) return (x/1000).toString()+"K"; return (x/1000000).toString()+"M"; }

fun run() {
    val n=readLine()!!.toInt()
    if(ok(n)) { println(format(n)); return; }
    var up=n; while(!ok(up)) { var tmp=up; var d=1; while(tmp%10==0) { tmp/=10; d*=10; }; up+=d; }
    var dn=n; while(!ok(dn)) { var tmp=dn; var d=1; while(tmp%10==0) { tmp/=10; d*=10; }; dn-=d; }
    println(if(up-n<=n-dn) format(up) else format(dn))
 }

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}