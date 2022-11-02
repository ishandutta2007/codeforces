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

double BF(int *A,int n,int p)
{
    ll f=1;
    rep(i,1,n+1)
        f*=i;
    int P[10];
    rep(i,0,n)
        P[i]=i;
    ll sum=0;
    do
    {
        int cnt=0;
        int s=0;
        rep(i,0,n)
        {
            if (s+A[P[i]]>p) break;
            s+=A[P[i]];
            ++cnt;
        }
        sum+=cnt;
    }
    while (next_permutation(P,P+n));
    return sum/double(f);
}

void run()
{
    ll C[60][60]={0};
    rep(i,0,60)
    {
        C[i][0]=1;
        rep(j,1,i+1)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    
    int n;
    int A[100];
    cin>>n;
    int s=0;
    rep(i,0,n)
        scanf("%d",A+i);
    rep(i,0,n)
        s+=A[i];
    int p;
    cin>>p;
    if (s<=p)
    {
        printf("%d\n",n);
        return;
    }
    ll S[60]={0};
    rep(mid,0,n)
    {
        ll D[52][52][52]={0};
        D[0][0][0]=1;
        rep(i,1,n+1)
        {
            rep(j,0,p+1)
                D[i][0][j]=D[i-1][0][j];
            rep(cnt,1,n+1)
            {
                rep(j,0,p+1)
                {
                    D[i][cnt][j]=D[i-1][cnt][j];
                    if (j>=A[i-1] && i-1!=mid)
                        D[i][cnt][j]+=D[i-1][cnt-1][j-A[i-1]];
                }
            }
        }
        rep(cnt,0,n+1)
            rep(j,0,p+1)
                if (j+A[mid]>p)
                    S[cnt]+=D[n][cnt][j];
    }
    double res=0;
    rep(cnt,0,n)
    {
        res+=S[cnt]/double(C[n][cnt]*(n-cnt))*cnt;
    }
    cout<<res<<endl;
    //cout<<BF(A,n,p)<<endl;
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