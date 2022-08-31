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

func main() {
  in := NewInput()
  N := in.IntToken()
  M := in.IntToken()

  P := make([]int, N)
  for i := 0; i < N; i++ {
    P[i] = in.IntToken() - 1
  }

  G := make([][]int, N)
  for i := 0; i < M; i++ {
    u := in.IntToken() - 1
    v := in.IntToken() - 1
    G[v] = append(G[v], u)
  }

  result := 0
  max_freq := 0
  freq := make([]int, N)
  for i := N - 1; i >= 0; i-- {
    if i != N - 1 && freq[P[i]] == max_freq {
      result++
    } else {
      max_freq++
      for _, u := range G[P[i]] {
        freq[u]++
      }
    }
  }

  fmt.Println(result)
}