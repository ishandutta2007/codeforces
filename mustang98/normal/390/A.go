package main

import (
    "fmt"
    "bufio"
    "os"
)

func main() {
    var (
        n, x, y        int
        roomHorizontal  = make(map[int]bool)
        roomVertical = make(map[int]bool)
    )
    
    scanner := bufio.NewScanner(os.Stdin)

    scanner.Scan()
    fmt.Sscanf(scanner.Text(), "%d", &n)

    cntHor := 0
    cntVer := 0

    for i := 0; i < n; i++ {
        scanner.Scan()
        fmt.Sscanf(scanner.Text(), "%d %d", &x, &y)
        
        _, ok := roomHorizontal[x]
        if !ok {
            roomHorizontal[x] = true
            cntHor++
        }

        _, ok = roomVertical[y]
        if !ok {
            roomVertical[y] = true
            cntVer++
        }
    }

    if cntHor > cntVer {
        fmt.Println(cntVer)
        return
    }

    fmt.Println(cntHor)
}