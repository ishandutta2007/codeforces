import java.util.*

const val MAX_VALUE = 200_005

var n: Int = 0
var sequence: IntArray = IntArray(0)
var count: IntArray = IntArray(0)

fun check(permutationSize: Int, doPaint: Boolean = false): Boolean {
    val queue: Queue<Int> = LinkedList<Int>()
    val used = BooleanArray(n + 1) { false }
    for (x in sequence) {
        if (x > permutationSize) {
            if (doPaint) {
                print('B')
            }
            continue
        }
        if (used[x]) {
            if (queue.isEmpty() || queue.poll() != x) {
                return false
            }
            if (doPaint) {
                print('R')
            }
        } else {
            used[x] = true
            queue.add(x)
            if (doPaint) {
                print('G')
            }
        }
    }
    return queue.isEmpty()
}

fun main() {
    n = readLine()!!.toInt()
    sequence = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    count = IntArray(MAX_VALUE) { 0 }
    sequence.forEach { x -> count[x]++ }

    var low = 0
    var high = 1
    var middle = 0

    while (count[high] == 2) {
        high++
    }

    while (high - low > 1) {
        middle = (low + high) / 2
        if (check(middle)) {
            low = middle
        } else {
            high = middle
        }
    }

    check(low, true)
}