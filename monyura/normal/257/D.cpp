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
#include <numeric>


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

bool solve(int *A,int n)
{
    rep(i,0,1<<n)
    {
        int s=0;
        rep(j,0,n)
            if ((i>>j)&1)
                s+=A[j];
            else
                s-=A[j];
        if (s>=0 && s<=A[0])
        {
            /*rep(j,0,n)
                if ((i>>j)&1)
                    printf("+");
                else
                    printf("-");
            puts("");*/
            return true;
        }
    }
    return false;
}

bool linear(int *A,int n)
{
    char Res[100100]={0};
    int S=A[n-1];
    for (int i=n-2;i>=0;i--)
        if (abs(S+A[i])<=A[i])
        {
            S+=A[i];
            Res[i]=0;
        }
        else
        {
            S-=A[i];
            Res[i]=1;
        }
    if (S<0)
    {
        rep(i,0,n)
            Res[i]^=1;
        S=-S;
    }
    if (S>A[0])
    {
        fprintf(stderr,"error\n");
        return false;
    }
    rep(i,0,n)
    {
        printf("%c",Res[i] ? '-':'+');
    }
    puts("");
    return true;
    
}

void run()
{
    int A[100100];
    int n;
    cin>>n;
    rep(i,0,n)
        scanf("%d",A+i);
    linear(A,n);
    //int n = 7;
    //rep(i,0,100)
    //{
    //  A[0]=rand()%20+1;
    //  rep(j,1,n)
    //      A[j]=A[j-1]+(rand()%(A[j-1]+1));
    //  rep(j,0,n)
    //      printf("%d ",A[j]);
    //  puts("");
    //  //bool r=solve(A,n);
    //  bool a=linear(A,n);
    //  //if (r!=a)
    //}
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