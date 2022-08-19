#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
int N, T, A[MAXN];

int main(){
  ios::sync_with_stdio(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> T;
    A[T] = 1;
  }
  for(int i = 1; i < MAXN; i++){
    if(!A[i]) continue;
    for(int j = i + i; j < MAXN; j += i){
      if(!A[j]) continue;
      A[j] = max(A[j], A[i] + 1);
    }
  }
  cout << max(*max_element(A, A + MAXN), 1) << '\n';
}