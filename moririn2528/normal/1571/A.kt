//val n = readLine()!!.toInt();
//var list = readLine()!!.split(" ").map{it.toInt()}.toMutableList()
import kotlin.math.*

fun main(){
    var n = readLine()!!.toInt();
    for(i in 1..n){
        var str = readLine()!!;
        var a=0;
        var b=0;
        var c=0;
        for(ca in str){
            if(ca=='<')a++;
            if(ca=='>')b++;
            if(ca=='=')c++;
        }
        if(a>0 && b>0)println("?");
        else if(a>0)println("<");
        else if(b>0)println(">");
        else println("=");
    }
}