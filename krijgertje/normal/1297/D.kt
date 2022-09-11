import kotlin.math.*

class Employee(val salary:Int,val id:Int) { var bonus=0; }

fun run() {
    val (n,budget)=readLine()!!.split(" ").map{it.toInt()}
    val employees=readLine()!!.split(" ").mapIndexed{idx,sal->Employee(sal.toInt(),idx)}
    val bysal=employees.sortedByDescending{it.salary}
    val maxsal=bysal[0].salary
    var rem=budget
    for(i in 0 until n) {
        val lim=maxsal-i
        val cur=min(rem,lim-bysal[i].salary)
        assert(cur>=0)
        rem-=cur; bysal[i].bonus+=cur;
    }
    val whole=rem/n; rem%=n;
    for(i in 0 until n) bysal[i].bonus+=whole+(if(i<rem) 1 else 0)
    println(employees.map{it.bonus}.joinToString(" "))
    
}

fun main() {
    val ncase=readLine()!!.toInt()
    for(i in 1..ncase) run()
}