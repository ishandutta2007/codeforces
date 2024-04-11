fun between(x:Int, l:Int, r:Int): Boolean = l<=x&&x<=r

fun main(args: Array<String>) {
    val (a,x,y)=readLine()!!.split(' ').map(String::toInt)
	println(when{between(x,1,a-1)&&between(y,1,a-1) -> 0; between(x,0,a)&&between(y,0,a) -> 1; else -> 2})
}