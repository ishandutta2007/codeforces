data class Robot(val x: Int, val left: Boolean, var ans: Int = -1)

fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val x = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        val left = readLine()!!.split(' ').map { it == "L" }.toBooleanArray()
        val robots = List(n) { Robot(x[it], left[it]) }
        solve(robots.filter { it.x % 2 == 0 }, m)
        solve(robots.filter { it.x % 2 == 1 }, m)
        for ((_, _, ans) in robots) print("$ans ")
        println()
    }
}

fun solve(robots: List<Robot>, m: Int) {
    val stack = ArrayDeque<Robot>()
    for (robot in robots.sortedBy { it.x }) {
        if (stack.isEmpty() || stack.last().left || !robot.left) {
            stack.addLast(robot)
        } else {
            val time = (robot.x - stack.last().x) / 2
            stack.removeLast().ans = time
            robot.ans = time
        }
    }
    while (stack.size >= 2 && stack[0].left && stack[1].left) {
        val time = (stack[0].x + stack[1].x) / 2
        stack.removeFirst().ans = time
        stack.removeFirst().ans = time
    }
    while (stack.size >= 2 && !stack[stack.lastIndex].left && !stack[stack.lastIndex - 1].left) {
        val time = m - (stack[stack.lastIndex].x + stack[stack.lastIndex - 1].x) / 2
        stack.removeLast().ans = time
        stack.removeLast().ans = time
    }
    if (stack.size <= 1) return
    val time = (stack.first().x + (m - stack.last().x) + m) / 2
    stack.first().ans = time
    stack.last().ans = time
}

fun Boolean.toInt() = if (this) 1 else 0

fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)