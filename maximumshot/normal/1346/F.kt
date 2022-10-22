import java.lang.Integer.min

val N: Int = 1005
var a = ArrayList<ArrayList<Long>>()
var sum_row = ArrayList<Long>()
var sum_col = ArrayList<Long>()
var sum_mul_row = ArrayList<Long>()
var pref_sum = ArrayList<Long>()
var pref_sum_mul = ArrayList<Long>()

fun solveA() {
    var (n, m, q) = readLine()!!.split(" ").map { x -> x.toInt() }

    for (i in 0 until n) {
        var tmp = readLine()!!.split(" ").map { x -> x.toLong() }
        var tmp_a = ArrayList<Long>()
        for (t in tmp)
            tmp_a.add(t)
        a.add(tmp_a)
    }

    for (j in 0 until m) {
        sum_col.add(0)
    }

    for (i in 0 until n) {
        sum_row.add(0)
        sum_mul_row.add(0)
    }

    for (i in 0 until n) {
        for (j in 0 until m) {
            sum_mul_row[i] += i.toLong() * a[i][j].toLong()
            sum_row[i] += a[i][j].toLong()
            sum_col[j] += a[i][j].toLong()
        }
    }

    for (iter in 0 until q + 1) {
        var x = 0
        var y = 0
        var z: Long = 0
        if (iter > 0) {
            var tmp = readLine()!!.split(" ").map { f -> f.toInt() }
            x = tmp[0]
            y = tmp[1]
            z = tmp[2].toLong()
        } else {
            x = 1
            y = 1
            z = a[0][0]
        }

        x--
        y--

        var dx: Long = z.toLong() - a[x][y].toLong()
        a[x][y] += dx
        sum_row[x] += dx
        sum_col[y] += dx
        sum_mul_row[x] += dx * x

        pref_sum.clear()
        pref_sum_mul.clear()
        for (i in 0 until m) {
            pref_sum.add(0)
            pref_sum_mul.add(0)
        }

        for (j in 0 until m) {
            if (j > 0) {
                pref_sum[j] = pref_sum[j - 1]
                pref_sum_mul[j] = pref_sum_mul[j - 1]
            }
            pref_sum[j] += sum_col[j]
            pref_sum_mul[j] += sum_col[j] * j.toLong()
        }

        var sum_up: Long = 0
        var sum_down: Long = 0
        var sum_mul_up: Long = 0
        var sum_mul_down: Long = 0

        for (i in 0 until n) {
            sum_down += sum_row[i]
            sum_mul_down += sum_mul_row[i]
        }

        var res_row = 4.toLong() * 1000000000.toLong() * 1000000000.toLong()
        var res = 4.toLong() * 1000000000.toLong() * 1000000000.toLong()

        for (i in 0 until n) {
            var total: Long = (sum_mul_down - i.toLong() * sum_down) + (i.toLong() * sum_up - sum_mul_up)
            if (res_row > total)
                res_row = total
            if (i + 1 < n) {
                sum_up += sum_row[i]
                sum_mul_up += sum_mul_row[i]

                sum_down -= sum_row[i]
                sum_mul_down -= sum_mul_row[i]
            }
        }

        for (j in 0 until m) {
            var sum_left = pref_sum[j]
            var sum_right = pref_sum[m - 1] - pref_sum[j]
            var sum_mul_left = pref_sum_mul[j]
            var sum_mul_right = pref_sum_mul[m - 1] - pref_sum_mul[j]

            var tmp = res_row
            tmp += (sum_left * j - sum_mul_left)
            tmp += (sum_mul_right - sum_right * j)
            if (res > tmp)
                res = tmp
        }

        print("$res ")
    }
    println()
}

fun main() {
//    val tt = readLine()!!.toInt()
    val tt = 1
    for (ti in 0 until tt) {
        solveA()
    }
}