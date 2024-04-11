#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5 + 5;
int v[N];
long long ans[N];
int main()
{
  //freopen(".in","r",stdin);
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int n;
  cin>>n;
  for(int i = 1;i<=n; i++){
    cin>>v[i];
  }
  sort(v + 1, v+ n+ 1);
  string s;
  cin>>s;
  s = " " + s;
  int j = n;
  for(int i =n ;i>=1; i--){
    if(s[i] != s[i - 1]){
      if(s[i] == 'L')
        ans[i] = v[j--];
      else
        ans[i] = - v[j--];
    }
  }
  long long sc = 0;
  int auxi = 1;
  int nexti = 0;
  for(int i = 1; i<=n; i = nexti){
    nexti = i + 1;
    while(nexti <= n && ans[nexti] == 0)
      nexti++;
    int len = nexti - i - 1;
    sc += 1LL * ans[i];
    i++;
    for(int j = auxi + len - 1; j >= auxi; j--, i++){
      if(s[i] == 'L'){
        if(sc - v[j] <= 0)
          ans[i] = v[j];
        else
          ans[i] = -v[j];
      }
      else if(s[i] == 'R'){
        if(sc + v[j] >= 0){
          ans[i] = -v[j];
        }
        else{
          ans[i] = v[j];
        }
      }
      sc += ans[i];
    }
    auxi += len;
  }
  for(int i =1 ; i<=n; i++){
    if(ans[i] > 0){
      cout<<ans[i]<<" L\n";
    }
    else{
      cout<<-ans[i]<<" R\n";
    }
  }
  return 0;
}