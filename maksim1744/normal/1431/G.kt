/*
    author:  Maksim1744
    created: 12.11.2020 18:59:00
*/

import kotlin.math.max;

fun main() {
    var (n, K) = readLine()!!.split(" ").map{ it.toInt() }
    var a = readLine()!!.split(" ").map{ it.toInt() }.toList().sorted()

    // println("$a")

    var dp = arrayOf<Array<Int>>()
    var inf = 1000000000
    for (i in 0 until n) {
        var array = arrayOf<Int>()
        for (j in 0 until n + 1) {
            array += -inf
        }
        dp += array
    }
    dp[0][0] = 0

    var sm = arrayOf<Array<Int>>()
    for (i in 0 until n) {
        var array = arrayOf<Int>()
        for (j in 0 until n) {
            array += 0
        }
        sm += array
    }

    for (i in 0 until n - 1) {
        sm[i][i + 1] = a[i + 1] - a[i];
    }
    for (ln in 4..n) {
        if (ln % 2 == 1) {
            continue;
        }
        for (l in 0 until n) {
            var r = l + ln - 1;
            if (r >= n) {
                break;
            }
            sm[l][r] = sm[l + 1][r - 1] + a[r] - a[l];
        }
    }

    for (i in 1 until n) {
        for (k in 0 until n + 1) {
            dp[i][k] = dp[i - 1][k]
            if (i % 2 == 1 && (i + 1 == k)) {
                dp[i][k] = max(dp[i][k], sm[0][i]);
            }
            for (ln in 2 until n + 1) {
                if (ln % 2 == 1) {
                    continue;
                }
                if (i < ln) {
                    break;
                }
                if (ln > k) {
                    break;
                }
                dp[i][k] = max(dp[i][k], dp[i - ln][k - ln] + sm[i - ln + 1][i])
            }
        }
    }
    println(dp[n - 1][K * 2])
}