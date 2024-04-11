package main 

import (
    "fmt"
    "bufio"
    "os"
)

func Readln(r *bufio.Reader) (string) {
  var (isPrefix bool = true
       err error = nil
       line, ln []byte
      )
  for isPrefix && err == nil {
      line, isPrefix, err = r.ReadLine()
      ln = append(ln, line...)
  }
  return string(ln)
}

func main() {
	var n, c1, c2 int
	fmt.Scan(&n, &c1, &c2)
	reader := bufio.NewReader(os.Stdin)
    s := Readln(reader)
    s = Readln(reader)
    n0, n1 := 0, 0
    for i:=0; i<n; i++ {
        if s[i]=='0' {
            n0++;
        } else {
            n1++;
        }
    }
    var ret int64
    for i:=1; i<=n1; i++ {
        var p, q int
        p = n / i;
        q = n % i;
        var cur int64
        cur = int64(i-q)*(int64(c1)+int64(c2)*int64(p-1)*int64(p-1)) + int64(q)*(int64(c1)+int64(c2)*int64(p)*int64(p));
        if i==1 || cur<ret { ret=cur }
    }
    fmt.Println(ret)
}