#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
char v[55];
long long dst (char a, char b)
{
    if(a>b)
        swap(a,b);
    return min(b-a,a+26-b);
}
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand ( time(NULL) );*/
    long long p,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,nri=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cin>>n;
    cin>>v;
    for(i=3;i<n;++i)
        mn=min(mn,dst('A',v[i-3])+dst('C',v[i-2])+dst('T',v[i-1])+dst('G',v[i]));
    cout<<mn;
    return 0;
}