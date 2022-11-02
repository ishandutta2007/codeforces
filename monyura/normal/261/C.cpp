#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

ll C[60][60]={0};

ll getCnt(ll n,int Ones)
{
    int A[100];
    ll a=n;
    int len=0;
    while (a)
    {
        A[len++]=a&1;
        a>>=1;
    }
    ll res=0;
    int cnt=0;
    for (int i=len-1;i>=0;i--)
    {
        if (cnt>Ones)
            break;
        if (A[i]==1)
        {
            int need=Ones-cnt;
            if (need<=i)
                res+=C[i][need];
            cnt++;
        }
    }
    if (cnt==Ones)
        res++;
    return res;
}

void run()
{
    rep(i,0,60)
    {
        C[i][0]=1;
        rep(j,1,i+1)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    ll n,t;
    cin>>n>>t;
    n++;
    if ((t&-t)!=t)
    {
        puts("0");
        return;
    }
    int Ones=0;
    while (t)
    {
        Ones++;
        t>>=1;
    }
    ll res=getCnt(n,Ones);
    if (Ones==1) res--;
    cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    //freopen("barns.in","r",stdin);
    //freopen("barns.out","w",stdout);
#endif
    run();
#ifdef _MONYURA_
    printf("=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

    return 0;
}

/*
10 10 92
11 10 92
*/