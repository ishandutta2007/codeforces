package main

import "fmt"
import "bufio"
import "os"
import "strconv"

type input struct {
  scanner *bufio.Scanner
}

func NewInput() input {
  in := input{scanner: bufio.NewScanner(os.Stdin)}
  in.scanner.Split(bufio.ScanWords)
  return in
}

func (in *input) Token() string {
  in.scanner.Scan()
  return in.scanner.Text()
}

func (in *input) IntToken() int {
  result, _ := strconv.Atoi(in.Token())
  return result
}

func main() {
  in := NewInput()

  N := in.IntToken()
  var ends []int
  for i := 0; i < N; i++ {
    in.IntToken()
    b := in.IntToken()
    ends = append(ends, b)
  }
  k := in.IntToken()

  result := 0
  for i := 0; i < N; i++ {
    if k <= ends[i] {
      result++
    }
  }
  fmt.Println(result)
}