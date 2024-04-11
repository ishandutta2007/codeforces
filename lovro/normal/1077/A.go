package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    stdin := bufio.NewReader(os.Stdin)
    var t int
    var a, b, k int64
    fmt.Fscan(stdin, &t)
    for i := 0; i < t; i++ {
        fmt.Fscan(stdin, &a, &b, &k)
        n := k / 2
        fmt.Println(n*a - n*b + (k%2)*a)
    }
}