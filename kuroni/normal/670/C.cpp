#include <bits/stdc++.h>
using namespace std;
map<int,int> cnt;
main()
{
    ios_base::sync_with_stdio(0);
    int n,m,a,ans=0,maxb=0,maxc=0,b[200000],c[200000];
    cin>>n;
    for (int i=0;i<n;i++) {cin>>a;cnt[a]++;}
    cin>>m;
    for (int i=0;i<m;i++) cin>>b[i];
    for (int i=0;i<m;i++) cin>>c[i];
    for (int i=0;i<m;i++) if ((!ans)||(cnt[b[i]]>cnt[maxb])||((cnt[b[i]]==cnt[maxb])&&(cnt[c[i]]>cnt[maxc]))) {ans = i+1;maxb=b[i];maxc=c[i];}
    cout<<ans;
}