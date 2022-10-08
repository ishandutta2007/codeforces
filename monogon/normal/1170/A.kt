
fun main(args: Array<String>) {
    var q: Int = readLine()!!.toInt();
    while(q-- > 0) {
        val (x, y) = readLine()!!.split(' ').map(String::toInt);
        val a = minOf(x, y) - 1;
        println("${x - a} ${y - a} ${a}");
    }
}