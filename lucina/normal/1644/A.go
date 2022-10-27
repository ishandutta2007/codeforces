package main

import (
	"fmt"
)

func solve() {
	var s string
	fmt.Scanf("%s\n", &s)

	x := make(map[byte]bool)
	rs := []byte(s)
	for i := 0; i < 6; i += 1 {
		if rs[i] >= 'a' && rs[i] <= 'z' {
			x[rs[i]] = true
		} else {
			c := 'a' + rs[i] - 'A'
			if !x[c] {
				fmt.Printf("NO\n")
				return
			}
		}
	}
	fmt.Printf("YES\n")

}

func main() {
	var T int
	for fmt.Scanf("%d\n", &T); T > 0; T-- {
		solve()
	}

}