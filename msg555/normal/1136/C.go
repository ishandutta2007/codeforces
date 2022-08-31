package main

import (
  "fmt"
  "bufio"
  "os"
  "strconv"
  "sort"
  "reflect"
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

func ReadDiags(in input, N, M int) [][]int {
  result := make([][]int, N + M - 1)
  for r := 0; r < N; r++ {
    for c := 0; c < M; c++ {
      result[r + c] = append(result[r + c], in.IntToken())
    }
  }
  for i := 0; i < N + M - 1; i++ {
    sort.Slice(
      result[i],
      func(a, b int) bool { return result[i][a] < result[i][b] },
    )
  }
  return result
}

func main() {
  in := NewInput()
  N := in.IntToken()
  M := in.IntToken()

  A := ReadDiags(in, N, M)
  B := ReadDiags(in, N, M)

  if reflect.DeepEqual(A, B) {
    fmt.Println("YES")
  } else {
    fmt.Println("NO")
  }
}