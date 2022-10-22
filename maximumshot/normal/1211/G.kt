import java.util.*
import kotlin.collections.ArrayList

class Tree (
    private var vertexNumber: Int,
    private var colors: IntArray,
    private var targetColors: IntArray,
    private var edges: ArrayList<Pair<Int, Int>>
) {
    private var arcs: Array<TreeSet<Int>> = emptyArray()

    /**
     * Clears and initializes lists of the adjacency lists for all vertices
     * */
    private fun initArcs() {
        arcs = Array(vertexNumber) { TreeSet<Int>() }
        for (v in 0 until vertexNumber) {
            arcs[v].clear()
        }
        for (edge in edges) {
            addEdge(edge.first - 1, edge.second - 1) // 1-index to 0-indexed
        }
    }

    /**
     * Adds the undirected edges into the tree
     * @param u is the first vertex of the edge
     * @param v is the second vertex of the edge
     * */
    private fun addEdge(u: Int, v: Int) {
        arcs[u].add(v)
        arcs[v].add(u)
    }

    /**
     * Removes the undirected edge from the tree
     * @param u is the first vertex of the edge
     * @param v is the second vertex of the edge
     * */
    private fun removeEdge(u: Int, v: Int) {
        arcs[u].remove(v)
        arcs[v].remove(u)
    }

    /**
     * Removes all the leafs which have already satisfied
     * conditions, i.e. such leafs, which has target color at
     * the very beginning will be deleted from the tree. Note
     * that after removing the first layer of satisfied leafs
     * the next layer will be considered and so on
     * */
    private fun removeRealisedLeafs() {
        val queue = LinkedList<Int>()
        for (v in 0 until vertexNumber) {
            if (arcs[v].size == 1 && colors[v] == targetColors[v]) {
                queue.add(v)
            }
        }
        while (!queue.isEmpty()) {
            val v = queue.poll()
            if (arcs[v].size == 1) {
                val to = arcs[v].first()
                removeEdge(v, to)
                if (colors[to] == targetColors[to]) {
                    queue.add(to)
                }
            }
        }
    }

    /**
     * Finds the path from vertex {@code fr} to vertex {@code to}
     *
     * @param fr is the start vertex of the path
     * @param to is the finish vertex of the path
     *
     * @return the path from {@code fr} to {@code to}
     * */
    private fun getPath(fr: Int, to: Int): List<Int> {
        initArcs()
        val used = BooleanArray(vertexNumber) { false }
        val from = IntArray(vertexNumber) { -1 }
        val queue = LinkedList<Int>()
        used[fr] = true
        queue.add(fr)
        while (!queue.isEmpty()) {
            val v = queue.poll()
            for (u in arcs[v]) {
                if (!used[u]) {
                    used[u] = true
                    from[u] = v
                    queue.add(u)
                }
            }
        }
        val path = LinkedList<Int>()
        path.add(to)
        while (path.last() != fr) {
            path.add(from[path.last()])
        }
        path.reverse()
        return path
    }

    /**
     * Checks whether {@code path} can recolor vertices correctly
     *
     * @param path is the path to be checked
     * @return {@code true} iff {@code path} can recolor vertices correctly
     * */
    private fun checkPath(path: List<Int>): Boolean {
        val tmpColors = colors.copyOf()
        var previous: Int? = null
        for (v in path) {
            if (previous == null) {
                previous = v
                continue
            }
            tmpColors[previous] = tmpColors[v].also { tmpColors[v] = tmpColors[previous!!] }
            previous = v
        }
        return tmpColors.contentEquals(targetColors)
    }

    /**
     * Finds such a path, which can recolor vertices correctly
     * @return path itself if such exists. Otherwise {@code null}
     * will be returned
     * */
    fun findKingPath(): List<Int>? {
        if (colors.contentEquals(targetColors)) {
            return emptyList()
        }
        initArcs()
        removeRealisedLeafs()
        var firstLeaf: Int? = null
        var secondLeaf: Int? = null
        for (v in 0 until vertexNumber) {
            if (arcs[v].size == 1 && colors[v] != targetColors[v]) {
                when {
                    firstLeaf == null -> firstLeaf = v
                    secondLeaf == null -> secondLeaf = v
                    else -> return null
                }
            }
        }
        if (firstLeaf == null || secondLeaf == null) {
            return null
        }
        val firstPath = getPath(firstLeaf, secondLeaf)
        var resultPath: List<Int>? = null
        if (checkPath(firstPath)) {
            resultPath = firstPath
        } else {
            val secondPath = getPath(secondLeaf, firstLeaf)
            if (checkPath(secondPath)) {
                resultPath = secondPath
            }
        }
        return resultPath?.map { v -> v + 1 }
    }

    companion object {
        /**
         * Shows the path as the sequence of vertices in it
         **/
        fun showPath(path: List<Int>) {
            println(path.size)
            for (v in path) {
                print("${v} ")
            }
            println()
        }
    }
}

fun solve() {
    val vertexNumber = readLine()!!.toInt()
    val colors = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    val targetColors = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
    val edges = ArrayList<Pair<Int, Int>>()
    for (i in 1 until vertexNumber) {
        val (u, v) = readLine()!!.split(" ").map { it.toInt() }
        edges.add(Pair(u, v))
    }

    val tree = Tree(vertexNumber, colors, targetColors, edges)
    val path = tree.findKingPath()
    if (path == null) {
        println("No")
    } else {
        println("Yes")
        Tree.showPath(path)
    }
}

fun main() {
    val testNumber = readLine()!!.toInt()
    for (test in 0 until testNumber) {
        solve()
    }
}