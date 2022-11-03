#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int l[N],r[N];
long long ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]),ans+=l[i]+r[i]+1;
    sort(l+1,l+n+1);sort(r+1,r+n+1);
    for(int i=1;i<=n;i++) ans-=min(l[i],r[i]);
    cout<<ans;
    return 0;
}