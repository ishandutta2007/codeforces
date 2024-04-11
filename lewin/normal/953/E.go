package main 

import (
    "io/ioutil"
    "bufio"
    "os"
    "strconv"
)

func main() {
    out := bufio.NewWriter(os.Stdout)
    var n int
    ints := getInts()
    n, ints = ints[0], ints[1:]
    ret := make([]int, n, n)
    ridx := 0
    for i := 0; i < n; i++ {
        for ridx > 0 && ret[ridx-1] == ints[i] {
            ints[i]++
            ridx--
        }
        ret[ridx] = ints[i]
        ridx += 1
    }

    out.WriteString(strconv.Itoa(ridx) + "\n")
    for i := 0; i < ridx; i++ {
        out.WriteString(strconv.Itoa(ret[i]) + "\n")
    }
    out.Flush()
}


func getInts() []int {
    var buf []byte
    buf, _ = ioutil.ReadAll(os.Stdin)
    var ints []int
    num := int(0)
    found := false
    for _, v := range buf {
        if '0' <= v && v <= '9' {
            num = 10*num + int(v - '0')
            found = true
        } else if found {
            ints = append(ints, num)
            found = false
            num = 0
        }
    }
    if found {
        ints = append(ints, num)
        found = false
        num = 0
    }
    return ints
}