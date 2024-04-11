#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,l[maxn],r[maxn];
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d%d",&l[i],&r[i]);
    sort(l+1,l+1+n);
    sort(r+1,r+1+n);
    for(int i=1;i<=n;i++)
    ans+=(max(r[i],l[i]));
    printf("%lld\n",ans+n);
}