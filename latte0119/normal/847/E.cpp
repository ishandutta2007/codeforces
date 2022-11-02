#include <bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  string S;

  cin >> N;
  cin >> S;
  vector< int > latte, malta;
  for(int i = 0; i < N; i++) {
    if(S[i] == 'P') latte.push_back(i);
    else if(S[i] == '*') malta.push_back(i);
  }

  auto check = [&](int sz)
  {
    int rest = 0;

    auto hihumi = [&](int left, int right, int curr)
    {
      if(curr < left) return(right-curr <= sz);
      if(right < curr) return (true);
      int latte = 0, malta = 0;
      latte += curr - left;
      latte += right - left;

      malta += right - curr;
      malta += right - left;
      return (min(latte, malta) <= sz);
    };

    for(int i = 0; i < latte.size(); i++) {
      const int left = malta[rest];
      if(latte[i] - left > sz) return (false);
      while(rest < malta.size() && hihumi(left, malta[rest], latte[i])) ++rest;
      if(rest == malta.size()) return (true);
    }
    return (false);
  };

  int ng = 0, ok = N*5;
  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }

  cout << ok << endl;
}