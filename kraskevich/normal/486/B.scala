import java.util.Scanner
import java.util.Arrays

object Solution {
    def main(args: Array[String]) = {
	val in = new Scanner(System.in)
	val n = in.nextInt()
	val m = in.nextInt()
	val b: Array[Array[Int]] = new Array(n)
	var i = 0
	for (i <- 0 until n) {
	    b(i) = new Array(m)
	    var j = 0
	    for (j <- 0 until m)
		b(i)(j) = in.nextInt()
	}
	val a: Array[Array[Int]] = new Array(n)
	for (i <- 0 until n) {
	    a(i) = new Array(m)
	    Arrays.fill(a(i), 1)
	}
	for (i <- 0 until n) {
	    var j = 0
	    for (j <- 0 until m) {
		if (b(i)(j) == 0) {
		    var k = 0
		    for (k <- 0 until m)
			a(i)(k) = 0
		    for (k <- 0 until n)
			a(k)(j) = 0
		}
	    }
	}
	var ok = true
	for (i <- 0 until n) {
	var j = 0
	    for (j <- 0 until m) {
		var curr = 0
		var k = 0
		for (k <- 0 until m)
		    curr |= a(i)(k)
		for (k <- 0 until n)
		    curr |= a(k)(j)
		if (curr != b(i)(j))
		    ok = false
	    }
	}
	if (ok) {
	    println("YES")
	    for (i <- 0 until n) {
		var j = 0
		for (j <- 0 until m)
		    print(a(i)(j) + " ")
		println()
	    }
	} else {
	    println("NO")
	}
    }
}