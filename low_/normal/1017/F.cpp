#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<bitset>
#include<queue>
using namespace std;
#define mn 100005
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second
#define ui unsigned int
#define ll long long

const ui undef=(ui)(-1);

bitset<100000050> B;
int a, b, c, d;
ll n;
const int MX=3e8+1;

ui numer(ui u)
{
    if (u%6==5) return (u-5)/3;
    else if (u%6==1) return (u-1)/3-1;
    else return undef;
}

ui denumer(ui i)
{
    if (i%2==0) return i*3+5;
    else return (i+1)*3+1;
}

ui f(ui x)
{
    return (a*x*x*x+b*x*x+c*x+d);
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    //special sieve
    for (ui i=0; i<B.size(); ++i) B.set(i, 1);
    // cerr<<"...";
    ui tmp;
    for (ui i=0; i<B.size(); ++i) if (B[i]==1)
    {
        ui u=denumer(i);
        
        if (MX/u<u) continue;
        for (ui j=u*u; j<MX; j+=u)  
        {
            tmp=numer(j);
            if (tmp==undef) continue;
            B.set(tmp, 0);
        }
    }
    cin>>n>>a>>b>>c>>d;

    ui u, temp, F;
    vector <ui> T={2, 3};
    ui ans=0;
    for (int v:T)
    {
        temp=1;
        F=f(v);
        while (n/v>=temp)
        {
            temp*=v;
            ans+=(n/temp)*F;
            
        }
    }
    // cerr<<ans<<"\n";

    for (ui i=0; i<B.size(); ++i) if (B[i]==1)
    {
        u=denumer(i);
        temp=1;
        F=f(u);
        while (n/u>=temp)
        {
            temp*=u;
            ans+=(n/temp)*F;
        }
    }

    cout<<ans;

    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/