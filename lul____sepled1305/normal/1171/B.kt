import java.util.*

fun main(){
    val reader = Scanner(System.`in`)
    val y = reader.nextInt()
    val b=reader.nextInt()
    val r=reader.nextInt()
    var g:Int
    if(y>b-1) { g = b-1} else {g = y}
    if(r-2<g) {g=r-2}
    print(3*g+3)
}