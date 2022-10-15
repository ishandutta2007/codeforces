fun main() {
    val (n, k50) = readLine()!!.split(' ').map { it.toInt() }
    precomputeFactorials(n + 1)
    val k = k50 / 50
    val w = readLine()!!.split(' ').map { it.toInt() / 50 }.toIntArray()
    val ones = w.count { it == 1 }
    val twos = w.count { it == 2 }
    fun code(a: Int, b: Int, opposite: Boolean) = a * (n + 1) + b + (if (opposite) (n + 1) * (n + 1) else 0)
    val graph = List(code(n, n, true) + 1) { mutableListOf<Edge>() }

    run { // our shore
        for (a in 0..ones) {
            for (b in 0..twos) {
                for (remA in 0..a) {
                    for (remB in 0..b) {
                        if (remA == a && remB == b) continue
                        if ((a - remA) + 2 * (b - remB) > k) continue

                        graph[code(a, b, false)].add(Edge(code(remA, remB, true), c(a, remA) * c(b, remB)))
                        graph[code(remA, remB, true)].add(Edge(code(a, b, false), c(ones - remA, ones - a) * c(twos - remB, twos - b)))
                    }
                }
            }
        }
    }
    val initial = code(ones, twos, false)
    val dist = bfs(graph, initial)
    val verticesWithDist = List(dist.filter { it <= graph.size }.maxOf { it } + 1) { mutableListOf<Int>() }
    for (vertex in graph.indices) {
        if (dist[vertex] > graph.size) continue
        verticesWithDist[dist[vertex]].add(vertex)
    }
    val count = Array(graph.size) { 0.toModInt() }
    count[initial] = 1.toModInt()
    for (lvl in 0 until verticesWithDist.lastIndex) {
        for (cur in verticesWithDist[lvl]) {
            for ((next, localCount) in graph[cur]) {
                count[next] += count[cur] * localCount
            }
        }
    }
    val finish = code(0, 0, true)
    println(dist[finish].let { if (it >= graph.size) -1 else it })
    println(count[finish])
}

data class Edge(val next: Int, val cnt: ModInt)

fun bfs(graph: List<MutableList<Edge>>, source: Int): IntArray {
    val dist = IntArray(graph.size) { Int.MAX_VALUE }
    dist[source] = 0
    val bfs = ArrayDeque<Int>()
    bfs.addLast(source)
    while (bfs.isNotEmpty()) {
        val cur = bfs.removeFirst()
        for ((next, _) in graph[cur]) {
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1
                bfs.addLast(next)
            }
        }
    }
    return dist
}

val fact = mutableListOf<ModInt>()
val inv = mutableListOf<ModInt>()

fun c(n: Int, k: Int) = fact[n] * inv[k] * inv[n - k]

fun precomputeFactorials(max: Int) {
    fact.add(1.toModInt())
    inv.add(1.toModInt())
    for (i in 1 until max) {
        fact.add(fact.last() * i)
        inv.add(1.toModInt() / fact.last())
    }
}

const val MOD: Int = 1e9.toInt() + 7

fun Int.toModInt() = ModInt(this % MOD)
fun Long.toModInt() = ModInt(this % MOD)

inline class ModInt(private val value: Int) {
    fun toInt() = value
    override fun toString() = "$value"

    constructor(value: Long) : this(value.toInt())

    operator fun plus(other: ModInt) = ModInt((value + other.value).let { if (it >= MOD) it - MOD else it })
    operator fun minus(other: ModInt) = ModInt((value - other.value).let { if (it < 0) it + MOD else it })
    operator fun times(other: ModInt) = ModInt((value * 1L * other.value) % MOD)
    operator fun div(other: ModInt) = this * other.inverse()

    operator fun plus(other: Int) = plus(other.toModInt())
    operator fun minus(other: Int) = minus(other.toModInt())
    operator fun times(other: Int) = times(other.toModInt())
    operator fun div(other: Int) = div(other.toModInt())

    fun inverse() = power(MOD - 2)
    fun power(exp: Int): ModInt = when {
        exp == 0 -> ModInt(1)
        exp % 2 == 0 -> power(exp / 2).let { it * it }
        else -> this * power(exp - 1)
    }
}