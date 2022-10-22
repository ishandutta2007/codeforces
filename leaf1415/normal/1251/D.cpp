#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, s;
P p[200005];

bool check(llint x)
{
  llint sum = 0, cnt = 0;
  for(int i = 1; i <= n; i++){
    if(p[i].second < x){
      sum += p[i].first;
      continue;
    }
    llint tmp = p[i].first;
    if(cnt < (n+1)/2){
      tmp = max(p[i].first, x);
    }
    sum += tmp;
    if(tmp >= x) cnt++;
  }
  return cnt >= (n+1)/2 && sum <= s;
}

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for(int z = 0; z < T; z++){
    cin >> n >> s;
    for(int i = 1; i <= n; i++){
      cin >> p[i].first >> p[i].second;
    }
    sort(p+1, p+n+1);
    reverse(p+1, p+n+1);

    llint ub = 1e9+7, lb = 0, mid;
    while(ub-lb>1){
      mid = (ub+lb)/2;
      if(check(mid)) lb = mid;
      else ub = mid;
    }
    cout << lb << "\n";
  }
  flush(cout);

  return 0;
}