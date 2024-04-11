#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<short,short> pss;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

void run()
{
    int n;
    cin>>n;
    int A[601][601]={0};
    rep(i,0,n)
        rep(j,0,n)
            scanf("%d",&A[i][j]);
    int Curr[601][601],Prev[601][601];
    memset(Prev,0,sizeof(Prev));
    Curr[0][0]=Prev[0][0]=A[0][0];
    const int INF=1e9;
    rep(t,2,2*n)
    {
        rep(i,0,t)
            rep(j,0,t)
            {
                Curr[i][j]=-INF;
                if (i<t-1 && j<t-1 && Prev[i][j]>Curr[i][j])
                    Curr[i][j]=Prev[i][j];
                if (i!=0 && j<t-1 && Prev[i-1][j]>Curr[i][j])
                    Curr[i][j]=Prev[i-1][j];
                if (i!=0 && j!=0 && Prev[i-1][j-1]>Curr[i][j])
                    Curr[i][j]=Prev[i-1][j-1];
                if (i<t-1 && j!=0 && Prev[i][j-1]>Curr[i][j])
                    Curr[i][j]=Prev[i][j-1];
                Curr[i][j]+=A[i][t-1-i];
                if (i!=j)
                    Curr[i][j]+=A[j][t-1-j];
            }
       rep(i,0,t)
		   rep(j,0,t)
				Prev[i][j]=Curr[i][j];
    }
    printf("%d\n",Curr[n-1][n-1]);

}

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t beg=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("================\n");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/