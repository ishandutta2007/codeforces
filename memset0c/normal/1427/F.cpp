#include<bits/stdc++.h>
using namespace std;
const int N=2410;
int n,l,r,a[N];
vector<int> p;
tuple<int,int,int> tmp[2];
vector<tuple<int,int,int>> ans;
int main(){
#ifdef memset0
  freopen("1.in","r",stdin);
#endif
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  cin>>n;
  for(int i=1,x;i<=3*n;i++)cin>>x,a[x]=1;
  for(int i=1;i<=6*n;i++)p.push_back(i);
  for(int i=1;i<=2*n;i++){
    l=0,r=p.size()-1;
    while(l<r&&a[p[l]]==a[p[l+1]]&&a[p[l]]==a[p[l+2]])tmp[a[p[l]]]={p[l],p[l+1],p[l+2]},l+=3;
    while(l<r&&a[p[r]]==a[p[r-1]]&&a[p[r]]==a[p[r-2]])tmp[a[p[r]]]={p[r-2],p[r-1],p[r]},r-=3;
    // cerr<<l<<","<<r<<endl;5555
    if(l<r){
      for(int j=l;j+2<=r;j++)if((i&1)==a[p[j]]&&(i&1)==a[p[j+1]]&&(i&1)==a[p[j+2]]){
        ans.push_back({p[j],p[j+1],p[j+2]});
        goto next;
      }
    }
    ans.push_back(tmp[i&1]);
  next:
    // cout<<"> "<<get<0>(ans.back())<<" "<<get<1>(ans.back())<<" "<<get<2>(ans.back())<<endl;
    p.erase(find(p.begin(),p.end(),get<0>(ans.back())));
    p.erase(find(p.begin(),p.end(),get<1>(ans.back())));
    p.erase(find(p.begin(),p.end(),get<2>(ans.back())));
  }
  for(const auto &it:ans)cout<<get<0>(it)<<" "<<get<1>(it)<<" "<<get<2>(it)<<endl;
}