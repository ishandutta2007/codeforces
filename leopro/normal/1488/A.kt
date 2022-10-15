fun main() {
    repeat(readLine()!!.toInt()) {
        val (x, y) = readLine()!!.split(' ').map{ it.toLong() }
        var power = 1_000_000_000
        var ops = 0
        var z = y
        while (z > 0 && power > 0){
            while (x * power <= z) z -= x * power.also { ops++ }
            power /= 10
        }
        println(ops + z)
    }
}