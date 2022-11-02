import kotlin.math.min
 
fun main() {
    for (t in 1..readLine()!!.toInt()) {
    	var (a,b) = readLine()!!.split(" ").map { it.toInt() }
    	println(a + b)
    }
}