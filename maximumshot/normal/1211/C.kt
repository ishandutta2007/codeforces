
import java.lang.Integer.min

class IceCream(var low: Int = 0, var high: Int = 0, var cost: Int = 0) {
    fun read() {
        val (a, b, c) = readLine()!!.split(" ").map { it.toInt() }
        low = a
        high = b
        cost = c
    }
}

fun main() {
    var (n, k) = readLine()!!.split(" ").map { it.toInt() }
    val iceCreams: Array<IceCream> = Array(n) { IceCream() }
    for (iceCream in iceCreams) {
        iceCream.read()
    }
    var minAmount = 0L
    var maxAmount = 0L
    for (iceCream in iceCreams) {
        minAmount += iceCream.low
        maxAmount += iceCream.high
    }
    if (minAmount > k || maxAmount < k) {
        println("-1")
        return
    }
    k -= minAmount.toInt()
    iceCreams.sortBy { it.cost }
    var totalCost = 0L
    for (iceCream in iceCreams) {
        totalCost += iceCream.low.toLong() * iceCream.cost
        val take = min(k, iceCream.high - iceCream.low)
        k -= take
        totalCost += take.toLong() * iceCream.cost
    }
    println(totalCost)
}