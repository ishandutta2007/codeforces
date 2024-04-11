import java.util.*

    fun main(args: Array<String>) {
        val scanner = Scanner(System.`in`)
        val n: Int
        val m: Int
        n = scanner.nextInt()
        m = scanner.nextInt()
        val sumx = IntArray(n + 1)
        val sumy = IntArray(n + 1)
        val sum = Array(n + 1) { IntArray(n + 1) }
        val f1 = scanner.nextInt()
        val l1 = scanner.nextInt()
        var ans = 0
        for (i in 2..m) {
            val fi = scanner.nextInt()
            val li = scanner.nextInt()
            sumx[fi]++
            sumy[li]++
            sum[fi][li]++
        }
        for (i in 1..n) {
            for (j in 1..n) if (i != j) {
                if (i == f1 && j == l1) continue
                ans = if (i != f1 && j != l1) Integer.max(ans, sumx[i] + sumy[j] - sum[i][j]) else Integer.max(ans, sum[i][j])
            }
        }
        println(ans + 1)
    }