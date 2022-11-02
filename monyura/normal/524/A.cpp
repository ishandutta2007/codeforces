#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
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
#include <bitset>
#include <cassert>
#include <complex>


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
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;


const double PI = acos(-1.0);




void run()
{
    int n,k;
    cin>>n>>k;
    bool B[201][201] = {0};
    map<int, int> mp;
    int id[201];
    int cnt[201] = {0};
    vector<int> Ans[201];
    rep(i,0,n)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (mp.find(a) == mp.end())
        {
            int t = mp.size();
            mp[a] = t;
            id[t] = a;
        }
        if (mp.find(b) == mp.end())
        {
            int t = mp.size();
            mp[b] = t;
            id[t] = b;
        }
        B[mp[a]][mp[b]] = 1;
        B[mp[b]][mp[a]] = 1;
        cnt[mp[a]] ++;
        cnt[mp[b]] ++;
    }
    int f = mp.size();
    rep(i,0,f)
    {
        rep(j,0,f)
        if (i != j && !B[i][j])
        {
            int c = 0;
            rep(k,0,f)
            if (k != i && k != j)
            {
                c += B[i][k] && B[k][j];
            }
            if (c * 100 >= k * cnt[i])
                Ans[i].push_back(j);
        }
    }
    for (auto p : mp)
    {
        printf("%d: %d", id[p.second], (int)Ans[p.second].size());

        rep(i,0,Ans[p.second].size())
            Ans[p.second][i] = id[Ans[p.second][i]];
        sort(all(Ans[p.second]));
        rep(i,0,Ans[p.second].size())
            printf(" %d",             Ans[p.second][i]);
        puts("");
    }
    
}

//#define prob "exam"



int main()
{
#ifdef _MONYURA_
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}