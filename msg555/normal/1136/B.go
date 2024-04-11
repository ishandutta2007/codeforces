package main

import (
  "fmt"
  "bufio"
  "os"
  "strconv"
)

type input struct {
  scanner *bufio.Scanner
}

func NewInput() input {
  in := input{scanner: bufio.NewScanner(os.Stdin)}
  in.scanner.Split(bufio.ScanWords)
  return in
}

func (in* input) Token() string {
  in.scanner.Scan()
  return in.scanner.Text()
}

func (in* input) IntToken() int {
  result, _ := strconv.Atoi(in.Token())
  return result
}

func min(a, b int) int {
  if a < b {
    return a
  }
  return b
}

func Calc(N, k int) int {
  return N + (N + 1) + (k + N - 1)
}

func main() {
  in := NewInput()
  N := in.IntToken()
  k := in.IntToken()
  result := min(Calc(N, k - 1), Calc(N, N - k))
  fmt.Println(result)
}