/*
    author:  Maksim1744
    created: 26.10.2020 12:26:10
*/

fun test_case() {
    var (n, m) = readLine()!!.split(" ").map{ it.toInt() }
    var edges = mutableListOf<Triple<Int, Int, Int>>();
    for (i in 0 until m) {
        var (u, v, w) = readLine()!!.split(" ").map{ it.toInt() }
        --u;
        --v;
        edges.add(Triple(w, u, v));
    }
    edges.sortBy{ -it.first };
    var a = IntArray(n) {-1}
    for ((w, u, v) in edges) {
        if (a[u] > w && a[v] > w) {
            print("NO\n");
            return;
        }
        if (a[u] == -1) a[u] = w;
        if (a[v] == -1) a[v] = w;
    }
    print("YES\n");
    print(a.joinToString(" "));
    print("\n");
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}