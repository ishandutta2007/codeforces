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

bool check(string &A, string &B,int k, int x)
{
    string Res[51]={"",A,B};
    rep(i,3,k+1)
    Res[i] = Res[i-2] + Res[i-1];
    int cnt = 0;
    rep(i,0,Res[k].size()-1)
    cnt +=Res[k][i] == 'A' && Res[k][i+1] == 'C';
    return x == cnt;
}

void test(int k, int x, int n, int m)
{
    int B[51]={0};
    int E[51]={0};
    ll D[51][6] = {0};
    D[1][4] = 1;
    B[1] = E[1] = 0;
    D[2][5] = 1;
    B[2] = E[2] = 1;
    rep(i,3,k+1)
    {
        B[i] = B[i-2];
        E[i] = E[i-1];
        rep(j,0,6)
            D[i][j] = D[i-2][j] + D[i-1][j];
        D[i][(E[i-2]<<1)|B[i-1]]++;
        //  S[i] = S[i-2] + S[i-1];
    }
    //cout<<S[k].c_str()<<endl;
    rep(as,0,2)
    rep(af,0,2)
    rep(bs,0,2)
    rep(bf,0,2)
    {
        int len[2]={n,m};
        
        len[0] -= as + af;
        len[1] -= bs + bf;
        int i = 0;
        if (af && as)
            i |= 1;
        if (af && bs)
            i |= 2;
        if (bf && as)
            i |= 4;
        if (bf  && bs)
            i |= 8;
        if (len[0] < 0 )
            continue;
        if (len[1] < 0)
            continue;
        ll add = 0;
        rep(j,0,4)
        if ((i>>j)&1)
            add += D[k][j];
        rep(a, 0, len[0]/2+1)
        {
            rep(b,0,len[1]/2+1)
            {
                if (ll(a)*D[k][4] + ll(b)*D[k][5] + add == x)
                {
                    string A = "";
                    if (as)
                        A += "C";
                    rep(j,0,a)
                    A += "AC";
                    rep(j,0,len[0] - 2*a)
                    A+="D";
                    if (af)
                        A+="A";
                    printf("%s\n",A.c_str());
                    string B = "";
                    if (bs)
                        B += "C";
                    rep(j,0,b)
                    B += "AC";
                    rep(j,0, len[1] - 2*b)
                    B += "D";
                    if (bf)
                        B += "A";
                    printf("%s\n",B.c_str());
//                    if (!check(A,B,k,x))
//                    {
//                        //cout<<"fail"<<endl;
//                        //exit(0);
//                    }
                    return;
                }
            }
        }
    }
    puts("Happy new year!");
}


void run()
{
    int k,x,n,m;
    cin>>k>>x>>n>>m;
    test(k,x,n,m);
//    rep(k,1,20)
//    rep(x,1,100000)
//    test(k,x,1,1);
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