import java.util.*

class Graph {
    private val SIZE = 6
    private var adjacencyMatrix = Array(SIZE) { ArrayList<Pair<Int, Int>>() }

    fun addEdge(from: Int, to: Int, id: Int) {
        adjacencyMatrix[from].add(Pair(to, id))
    }

    fun dfs(v: Int, eulerCycle: ArrayList<Int>) {
        while (!adjacencyMatrix[v].isEmpty()) {
            val (to, id) = adjacencyMatrix[v].last()
            adjacencyMatrix[v].removeAt(adjacencyMatrix[v].size - 1)
            dfs(to, eulerCycle)
            eulerCycle.add(id)
        }
    }

    fun findEulerCycle(): List<Int> {
        val eulerCycle = ArrayList<Int>()
        dfs(0, eulerCycle)
        eulerCycle.reverse()
        return eulerCycle
    }
}

const val KOTLIN = "kotlin"

fun main() {
    val n = readLine()!!.toInt()
    val symbolToReminder = TreeMap<Char, Int>()
    for (i in 0 until KOTLIN.length) {
        symbolToReminder[KOTLIN[i]] = i
    }
    val graph = Graph()
    for (i in 0 until n) {
        val part = readLine()!!
        val from = symbolToReminder[part.first()]!!
        val to = (symbolToReminder[part.last()]!! + 1) % KOTLIN.length
        graph.addEdge(from, to, i)
    }
    val eulerCycle = graph.findEulerCycle()
    for (i in eulerCycle) {
        print("${i + 1} ")
    }
    println()
}