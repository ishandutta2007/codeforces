#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<long double> lcf[10];
vector<int> numbers[10];
int maxexp[] = {1, 1, 4, 4, 2, 1, 1, 4, 4, 2};
vector<long double> ans[10];
long double msol = DBL_MIN;
int cycle[10];
int cyclesol[10];
int d;
int pwr(int x, int pwr){
  int ans = 1;
  while(pwr)
    ans = ans * x % 10, pwr--;
  return ans;
}
void bkt(int k){
  if(k == 10){
    long double csol = 0;
    int prod = 1;
    for(int cf = 0; cf < 10 ;cf ++){
      csol += ans[cf][cycle[cf]];
      prod = prod * pwr(cf, cycle[cf]) % 10;
    }
    if(prod == d){
      if(csol > msol){
        msol = csol;
        for(int cf = 0; cf < 10; cf++)
          cyclesol[cf] = cycle[cf];

      }
    }
    return;
  }
  for(int i = 0; i <= maxexp[k] && i <=lcf[k].size(); i++){
    cycle[k] = i;
    bkt(k + 1);
  }
}
int main()
{
  //freopen(".in","r",stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin>>n>>d;
  for(int i = 1; i<=n; i++){
    int x;
    cin>>x;
    numbers[x%10].push_back(x);
    lcf[x%10].push_back(log(x));
  }
  for(int cf = 0; cf<=9; cf++){
    sort(lcf[cf].rbegin(), lcf[cf].rend());
    sort(numbers[cf].rbegin(), numbers[cf].rend());
  }
  for(int cf = 0; cf<= 9; cf++){
    long double cur = 0;
    ans[cf].resize(maxexp[cf] + 1);
    ans[cf][0] = 0;
    int curcnt = 1;
    for(int i = 0; i < lcf[cf].size(); i++){
      cur += lcf[cf][i];
      ans[cf][curcnt] = cur;
      curcnt++;
      if(curcnt > maxexp[cf])
        curcnt = 1;
    }
  }
  bkt(0);
  vector<int> rsp;
  if(msol == DBL_MIN){
    cout<<"-1";
    return 0;
  }
  for(int cf = 0; cf < 10; cf++){
    if(cyclesol[cf] == 0)
      continue;
    int lpoz = 0;
    int cff = 1;
    for(int i =0 ; i<lcf[cf].size(); i++){
      if(cff == cyclesol[cf])
        lpoz = i;
      cff++;
      if(cff > maxexp[cf])
        cff = 1;
    }
    for(int i = 0; i <= lpoz; i++)
      rsp.push_back(numbers[cf][i]);
  }
  cout<<rsp.size()<<"\n";
  for(auto x:rsp)
    cout<<x<<" ";
  return 0;
}