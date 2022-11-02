#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
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
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;


void run()
{
    char A[51][51];
    char B[51][51];
    int na,ma;
    cin>>na>>ma;
    rep(i,0,na)
        scanf(" %s",A[i]);
    int nb,mb;
    cin>>nb>>mb;
    rep(i,0,nb)
        scanf(" %s",B[i]);
    int best=-1,rx=-1,ry=-1;
    rep(x,-51,52)
        rep(y,-51,52)
        {
            int curr=0;
            rep(i,0,na)
                rep(j,0,ma)
                    if (i+x>=0 && i+x<nb && j+y>=0 && j+y<mb)
                        curr+=(A[i][j]-'0')*(B[i+x][j+y]-'0');
            if (curr>best)
            {
                best=curr;
                rx=x;
                ry=y;
            }
        }
    printf("%d %d\n",rx,ry);
    
}



int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
    run();
#ifdef _MONYURA_
    printf("=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/