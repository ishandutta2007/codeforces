#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+ 5;
int a[N];
int d[N];
long long maxsuf[N];
long long spart[N];
int main()
{
  //freopen(".in","r",stdin);
  ios::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int n,k;
  cin>>n>>k;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    cin>>d[i];
  }
  long long s = 0;
  int mini = INT_MAX;
  for(int i=1;i<=n;i++){
    spart[i] = spart[i-1];
    spart[i] += a[i];
    if(i<n)
      mini = min(mini, d[i]);
  }
  s = spart[n];
  if(k>=2){

    cout<<max(1LL*a[n] - d[n], max(s - mini,0LL));
    return 0;
  }
  if(k == 0){
    long long mans = 0;
    for(int i=1;i<=n;i++){
      mans = max(mans, spart[n] - spart[i-1] - d[i]);
    }
    cout<<mans;
    return 0;
  }
  long long maxans =  0;
  for(int i=1;i<n;i++){
    maxans =max(maxans, s - a[i + 1] - d[1] + max(0 , a[i + 1] - d[i + 1]));
  }
  for(int i = n;i>=1;i--){
    maxsuf[i] = max(maxsuf[i+1], spart[n] - spart[i-1] - d[i]);
    if(i > 1){
      maxans = max(maxans, maxsuf[i]);
    }
  }
  int minpref = d[1];
  maxans = max(maxans, maxsuf[2] + max(0 , a[1] - d[1]));
  for(int i=2;i<n;i++){
    minpref = min(minpref, d[i]);
    long long lft = spart[i] - minpref;
    long long rgt = maxsuf[i + 1];
    maxans = max(maxans, lft);
    maxans = max(maxans, rgt);
    maxans = max(maxans, lft + rgt);
  }
  cout<<maxans<<"\n";
  return 0;
}