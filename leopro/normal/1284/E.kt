fun main() {
    val n = readLine()!!.toInt()
    val pts = List(n) { readLine()!!.split(' ').map { it.toInt() }.run { Point(first(), last()) } }
    var magic = 0L
    for (i in pts.indices) {
        val top = pts.map { it - pts[i] }.filter { it.y > 0 || (it.y == 0 && it.x > 0) }.sortedWith { p, q ->
            sign(-p.x *1L* q.y + q.x *1L* p.y)
        }
        val bottom = pts.map { it - pts[i] }.filter { it.y < 0 || (it.y == 0 && it.x < 0) }.sortedWith { p, q ->
            sign(-p.x * 1L*q.y + q.x *1L* p.y)
        }
        var cur = 0
        for (j in top.indices) {
            while (cur < bottom.size && cross(bottom[cur], top[j]) < 0) cur++
            magic += pairs(cur + (top.lastIndex - j)) + pairs(j + (bottom.size - cur))
        }
    }
    val total = pairs(n) * 1L * pairs(n - 2)
    val quad = (2 * magic - total) / 2
    val cn4 = n * 1L * (n - 1) * (n - 2) * (n - 3) / 24
    println((cn4 - quad) * (n - 4) / 2)
}

data class Point(val x: Int, val y: Int) {
    operator fun minus(other: Point) = Point(x - other.x, y - other.y)
}

fun cross(p: Point, q: Point) = p.x * 1L * q.y - p.y * 1L * q.x
fun pairs(x: Int) = x * (x - 1) / 2
fun sign(x: Long) = if (x < 0) -1  else if (x > 0) 1 else 0