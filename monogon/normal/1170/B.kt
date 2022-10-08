
fun main(args: Array<String>) {
    readLine()!!.toInt()
    var a = readLine()!!.split(' ').map(String::toInt)
    var max1 = 0
    var max2 = 0
    var sum = 0
    for(x in a) {
        if(x < max2) {
            sum++
        }
        if(x >= max1) {
            max2 = max1
            max1 = x
        }else if(x >= max2) {
            max2 = x
        }
    }
    println(sum)
}