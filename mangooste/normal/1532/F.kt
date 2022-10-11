import java.util.Scanner

fun main() {
    val scanner = Scanner(System.`in`)
    var n = scanner.nextInt()
    var a = ArrayList<String>()
    var cnt = ArrayList<ArrayList<Int>>()
    repeat(n) {
        cnt.add(ArrayList<Int>())
    }
    for (i in 0..2 * n - 3) {
        a.add(scanner.next())
        cnt[a.get(i).length].add(i)
    }
    repeat(2) {
        var answer = ArrayList<Int>()
        repeat(2 * n - 2) {
            answer.add(0)
        }
        var pref = ArrayList<Char>()
        var suf = ArrayList<Char>()
        pref.add(a[cnt[1].get(0)][0])
        suf.add(a[cnt[1].get(1)][0])
        answer[cnt[1].get(1)] = 1
        var ok = true
        for (i in 2..n - 1) {
            var any = false
            repeat(2) {
                if (!any) {
                    var first = cnt[i].get(0)
                    var second = cnt[i].get(1)
                    var valid = true
                    for (j in 0..i - 2) {
                        if (a[first].get(j) != pref.get(j)) {
                            valid = false
                            break
                        }
                        if (a[second].get(j + 1) != suf.get(suf.size - j - 1)) {
                            valid = false
                            break
                        }
                    }
                    if (valid) {
                        any = true
                        pref.add(a[first].get(i - 1))
                        suf.add(a[second].get(0))
                        answer[second] = 1
                    }
                    cnt[i].reverse()
                }
            }
            if (!any) {
                ok = false
                break
            }
        }
        suf.add(pref.get(0))
        pref.add(suf.get(0))
        suf.reverse()
        if (pref == suf && ok) {
            for (i in answer) {
                if (i == 0) {
                    print("P")
                } else {
                    print("S")
                }
            }
            println()
            return
        }
        cnt[1].reverse()
    }
    println("cyka")
}