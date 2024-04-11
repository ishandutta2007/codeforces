package main 

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	ss := make([]string, n, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&ss[i])
	}
	var s string
	fmt.Scan(&s)
	dp := make([]int, len(s)+1, len(s)+1)
	for i := 0; i <= len(s); i++ {
		dp[i] = 1000000000
	}
	dp[0] = 0
	for i := 0; i <= len(s); i++ {
		for j := 0; j < n; j++ {
			var cpos int
			cpos = i
			for k := 0; k < len(ss[j]); k++ {
				if cpos < len(s) && s[cpos] == ss[j][k] {
					cpos += 1
				}
			}
			if dp[i] + 1 < dp[cpos] {
				dp[cpos] = dp[i] + 1
			}
		}
	}
	if dp[len(s)] < 1000000000 {
		fmt.Println(dp[len(s)])
	} else {
		fmt.Println("-1")
	}
}