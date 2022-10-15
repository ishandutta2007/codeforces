import kotlin.math.abs

fun main() {
    repeat(readLine()!!.toInt()) {
        val n = readLine()!!.toInt()
        val s = readLine()!!
        val a = readLine()!!.map { it == '1' }.toBooleanArray()
        val aim = s.map { '?' }.toCharArray()
        for (i in a.indices) {
            if (a[i]) {
                if (aim[i] == ')') return@repeat println(-1)
                aim[i] = '('
                if (aim[i + 3] == '(') return@repeat println(-1)
                aim[i + 3] = ')'
            }
        }
        for (attempt in 0..3) {
            for (i in a.indices) {
                if (a[i]) {
                    if (aim[i + 1] == aim[i + 2] && aim[i + 1] != '?') return@repeat println(-1)
                    if (aim[i + 1] == ')') aim[i + 2] = '('
                    if (aim[i + 1] == '(') aim[i + 2] = ')'
                    if (aim[i + 2] == ')') aim[i + 1] = '('
                    if (aim[i + 2] == '(') aim[i + 1] = ')'
                    if (aim[i + 1] == aim[i + 2] && attempt == 3) {
                        if (s[i + 1] == '(' || s[i + 2] == ')') {
                            aim[i + 1] = '('
                            aim[i + 2] = ')'
                        } else {
                            aim[i + 1] = ')'
                            aim[i + 2] = '('
                        }
                    }
                }
            }
        }
        println(s.zip(aim.joinToString("")).count { (a, b) -> abs(a.toInt() - b.toInt()) == 1 })
    }
}