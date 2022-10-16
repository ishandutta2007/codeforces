#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
struct ura
{
    long long a,b;
}v[200005];
bool cmp (ura a, ura b)
{
    return a.a-a.b>b.a-b.b;
}
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand ( time(NULL) );*/
    long long pz,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>v[i].a>>v[i].b;
    sort(v+1,v+n+1,cmp);
    long long s=0;
    for(i=1;i<=n;++i)
        s=s+v[i].a*1LL*(i-1)+v[i].b*1LL*(n-i);
    cout<<s;
    return 0;
}