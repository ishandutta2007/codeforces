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

type node struct  {
  sum, mx, psh int64
}

func (n *node) agg(lft, rht node) {
  n.sum = lft.sum + rht.sum
  n.mx = rht.mx
}

func Sum(arr []node, x, a, b, A, B int) int64 {
  if a <= A && B <= b {
    return arr[x].sum
  } else if b <= A || B <= a {
    return 0
  }
  M := (A + B) / 2
  if arr[x].psh != 0 {
    Increase(arr, 2 * x + 0, A, A, M, arr[x].psh)
    Increase(arr, 2 * x + 1, A, M, B, arr[x].psh)
    arr[x].psh = 0
  }
  return Sum(arr, 2 * x + 0, a, b, A, M) +
         Sum(arr, 2 * x + 1, a, b, M, B)
}

func Increase(arr []node, x, a, A, B int, val int64) {
  if B <= a {
    return
  } else if a <= A && arr[x].mx <= val {
    arr[x].mx = val
    arr[x].sum = val * int64(B - A)
    arr[x].psh = val
    return
  } else if (A + 1 == B) {
    return
  }
  M := (A + B) / 2
  if arr[x].psh != 0 {
    Increase(arr, 2 * x + 0, A, A, M, arr[x].psh)
    Increase(arr, 2 * x + 1, A, M, B, arr[x].psh)
    arr[x].psh = 0
  }
  Increase(arr, 2 * x + 0, a, A, M, val)
  if arr[2 * x + 0].mx <= val {
    Increase(arr, 2 * x + 1, a, M, B, val)
  }
  arr[x].agg(arr[2 * x + 0], arr[2 * x + 1])
}

const MAXN int = 1 << 18

func main() {
  in := NewInput()
  N := in.IntToken()

  A := make([]int, N)
  for i := 0; i < N; i++ {
    A[i] = in.IntToken()
  }

  K := make([]int, N - 1)
  for i := 0; i < N - 1; i++ {
    K[i] = in.IntToken()
  }

  arr := make([]node, MAXN * 2)

  ksum := int64(0)
  KSS := make([]int64, N + 1)
  for i := 0; i < N; i++ {
    if i == 0 {
      ksum += int64(A[0])
    } else {
      ksum += int64(K[i - 1])
    }
    val := int64(A[i]) - ksum
    KSS[i + 1] = KSS[i] + int64(ksum)
    arr[MAXN + i] = node{sum: val, mx: val}
  }
  for i := N; i < MAXN; i++ {
    arr[MAXN + i] = arr[MAXN + N - 1]
  }
  for i := MAXN - 1; i > 0; i-- {
    arr[i].agg(arr[2 * i + 0], arr[2 * i + 1])
  }

  Q := in.IntToken()
  for i := 0; i < Q; i++ {
    op := in.Token()
    a := in.IntToken() - 1
    b := in.IntToken()
    if op == "s" {
      fmt.Println(Sum(arr, 1, a, b, 0, MAXN) + KSS[b] - KSS[a])
    } else {
      cur := Sum(arr, 1, a, a + 1, 0, MAXN)
      Increase(arr, 1, a, 0, MAXN, cur + int64(b))
    }
  }
}