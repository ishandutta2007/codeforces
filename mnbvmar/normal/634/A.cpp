#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

/////////////////////////////////////////////////////////


const int MaxN = 200005;

int N;
int A[MaxN], B[MaxN];

void input(){
  cin >> N;
  for (int i = 0; i < N; i++) { cin >> A[i]; }
  for (int i = 0; i < N; i++) { cin >> B[i]; }
}

int main(){
  input();

  vector<int> AA, BB, Arot;
  for (int i = 0; i < N; i++) {
    if (A[i] != 0) { AA.push_back(A[i]); }
    if (B[i] != 0) { BB.push_back(B[i]); }
  }

  for (int i = 0; i < N - 1; i++) {
    if (AA[i] == BB[0]) {
      for (int j = 0; j < SZ(AA); j++) {
        Arot.push_back(AA[(i+j)%SZ(AA)]);
      }
    }
  }

  cout << (Arot == BB ? "YES\n" : "NO\n");
}