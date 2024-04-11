import java.util.PriorityQueue

fun main() {
    val tt = 1
    repeat(tt) {
        val (n, k, x) = readLine()!!.split(" ").map{it.toLong()}
        val a = readLine()!!.split(" ").map{it.toLong()}.toLongArray()
        var l: Long = -1
        var r: Long = 1002003004005006007
        while(r - l > 1) {
            val c = (r + l) / 2
            var cnt: Long = 0
            val q = PriorityQueue<Long>()
            var cur: Long = 0
            var acc: Long = 0
            for(ai in a) {
                acc += ai
                q.add(-ai)
                cur += 1
                while(acc > c && !q.isEmpty()) {
                    acc += q.remove()
                    cnt += 1
                    cur -= 1
                }
                if (acc > c) {
                    cnt = k + 1
                    break
                }
                if (cur == x) {
                    q.clear()
                    acc = 0
                    cur = 0
                }
            }
            if (cnt <= k) {
                r = c
            } else {
                l = c
            }
        }
        print(r)
    }
}