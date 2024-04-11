fun main() {
    var t = readLine()!!.toInt();
    for (test in 1..t) {
        var (n, k) = readLine()!!.split(" ").map{ it.toInt() };
        var n1 = n / (k * k * k + k * k + k + 1);
        for (i in 0..3) {
            print(n1);
            print(" ");
            n1 *= k;
        }
        print("\n");
    }
}