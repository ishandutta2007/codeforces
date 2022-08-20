/*
    author:  Maksim1744
    created: 12.11.2020 17:41:44
*/

fun test_case() {
    var s = readLine()!!
    var ans = 0
    var i = 0
    while (i < s.length) {
        if (i + 1 < s.length && s[i] == 'v' && s[i + 1] == 'v') {
            ans += 1;
            i += 2;
        } else if (s[i] == 'w') {
            ans += 1;
            i += 1;
        } else {
            i += 1;
        }
    }
    println(ans);
}

fun main() {
    var t = readLine()!!.toInt()
    for (test in 1..t) {
        test_case()
    }
}