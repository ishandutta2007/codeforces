#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#define LL long long
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
#define IOS ios_base::sync_with_stdio(0);

using namespace std;

const int N = 300005;
int A[N], n;
int main() {
  IOS
  long long suma = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> A[i];
    suma += A[i];
  }
  sort(A + 1, A + 1 + n);
  
  long long wynik = suma;
  
  for(int i = 1; i <= n - 1; i++) {
    wynik += suma;
    suma -= A[i];
  }
  
  cout<<wynik;
  
  return 0;
}