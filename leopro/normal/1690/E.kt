fun main() {
    repeat(readLine()!!.toInt()) {
        val (n, k) = readLine()!!.split(' ').map { it.toInt() }
        val a = readLine()!!.split(' ').map { it.toInt() }.toIntArray()
        var ans = a.map { it / k }.fold(0L) { a, b -> a + b }
        val residues = a.map { it % k }.sorted().toMutableList()
        var i = 0
        while (i < residues.lastIndex) {
            while (i < residues.lastIndex && residues.last() + residues[i] < k) i++
            if (i == residues.lastIndex) break
            i++
            residues.removeLast()
            ans++
        }
        println(ans)
    }
}

data class Cell(val i: Int, val j: Int)