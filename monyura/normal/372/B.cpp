#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif


#include <iostream>
#include <iomanip>
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

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int Fen2D[40][40][41][41]={0};

int S[50][50]={0};

inline int getS(int i,int j)
{
    return i < 0 || j < 0 ? 0 : S[i][j];
}

void run()
{
    int n,m,q;
    cin>>n>>m>>q;
    char A[50][50];
    memset(A,'0',sizeof(A));
    rep(i,0,n)
        A[i][m] = 0;
    rep(i,0,n)
        scanf("%s",A[i]);

    rep(i,0,n)
        rep(j,0,m)
            S[i][j] = getS(i-1,j) + getS(i,j-1) - getS(i-1,j-1) + (A[i][j]=='0');
    rep(i,0,n)
        rep(j,0,m)
        {
            rep(a,1,n+1)
                rep(b,1,m+1)
                {
                    int left = i - 1 < 0 ? 0 : Fen2D[i-1][j][a][b];
                    int up   = j - 1 < 0 ? 0 : Fen2D[i][j-1][a][b];
                    int corn = i - 1 < 0 || j - 1 < 0 ? 0 : Fen2D[i-1][j-1][a][b];
                    Fen2D[i][j][a][b] = left + up - corn;
                }
            rep(a,0,i+1)
                rep(b,0,j+1)
                {
                    int sum = getS(i,j) - getS(a-1,j) - getS(i,b-1) + getS(a-1,b-1);
                    int need = (i-a+1) * (j-b+1);
                    if (sum == need)
                    {
                        for (int x = a+1; x > 0 ; x -= x&-x)
                            for (int y = b+1; y > 0 ; y -= y&-y)
                                ++Fen2D[i][j][x][y];
                    }
                }
//            printf("[%d %d]\n",i,j);
//            rep(x,1,n+1)
//                rep(y,1,m+1)
//            printf("%d%c",Fen2D[i][j][x][y],y == m? '\n' : ' ');
//            puts("");

        }
    rep(i,0,q)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        --c;--d;
        int res = 0;
        for (int x = a; x<=n; x += x& -x)
            for (int y = b; y<=m; y += y&-y)
                res += Fen2D[c][d][x][y];
        printf("%d\n",res);
    }
}

//#define prob "kids"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
    #ifdef prob
        freopen(prob".in","r",stdin);
        freopen(prob".out","w",stdout);
    #endif
#endif
    
    run();
    
#ifdef _MONYURA_
    printf("\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}