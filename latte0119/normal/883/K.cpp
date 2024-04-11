#include<bits/stdc++.h>

using namespace std;

using int64 = long long;


int main()
{
  int N, S[200000], G[200000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S[i] >> G[i];
  }

  int latte = S[0], malta = S[0] + G[0];

  int low1[200000], high1[200000];
  int low2[200000], high2[200000];
  low1[0] = latte, high1[0] = malta;

  for(int i = 1; i < N; i++) {
    latte = max(latte - 1, S[i]);
    malta = min(malta + 1, S[i] + G[i]);
    low1[i] = latte;
    high1[i] = malta;
  }

  latte = S[N - 1], malta = S[N - 1] + G[N - 1];
  low2[N - 1] = latte, high2[N - 1] = malta;
  for(int i = N - 2; i >= 0; i--) {
    latte = max(latte - 1, S[i]);
    malta = min(malta + 1, S[i] + G[i]);
    low2[i] = latte;
    high2[i] = malta;
  }
  int64 ret = 0, ans[200000];
  for(int i = 0; i < N; i++) {
    auto beet1 = min(high1[i], high2[i]);
    auto beet2 = max(low1[i], low2[i]);

    if(beet2 > beet1) {
      cout << -1 << endl;
      return(0);
    }
    ans[i] = beet1;
    ret += beet1 - S[i];
  }

  cout << ret << endl;
  for(int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;

}