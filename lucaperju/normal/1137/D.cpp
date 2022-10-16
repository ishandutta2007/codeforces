#include <bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
const long long INF=100000000000000LL;
const long long mod=1000000007;
char v[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long pz,add=1,t,h,i,j,n,mn=10000030LL*10000030LL,k=0,mx=-999999999999LL,tot,m,obj,cnt=0,cnti=0,b2,a3,b3,a,b,ok=0;
    long long ra,rb,dv=-1,dv1=-1;
    cout<<"next 0 1\n";
    cout.flush();
    int rz;
    cin>>rz;
    for(i=1;i<=rz;++i)
        cin>>v;
    cout<<"next 1\n";
    cout.flush();
    cin>>rz;
    for(i=1;i<=rz;++i)
        cin>>v;
    cnt=1;
    while(1)
    {
        if(rz==2 && cnt&1)
            break;
        if(cnt&1)
        {
            cout<<"next 0 1\n";
            cout.flush();
            cin>>rz;
            for(i=1;i<=rz;++i)
                cin>>v;
        }
        else
        {
            cout<<"next 1\n";
            cout.flush();
            cin>>rz;
            for(i=1;i<=rz;++i)
                cin>>v;
        }
        ++cnt;
        if(rz==2 && cnt&1)
            break;
    }
    while(rz!=1)
    {
        cout<<"next 0 1 2 3 4 5 6 7 8 9\n";
        cout.flush();
        cin>>rz;
        for(i=1;i<=rz;++i)
            cin>>v;
    }
    cout<<"done\n";
    cout.flush();
    return 0;
}