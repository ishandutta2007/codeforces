#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
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

const int SZ = 300300;
const int DO_SZ = 4 * SZ;
int Ass[DO_SZ] = {0};

void setVal(int v,int l, int r, int ql, int qr, int val)
{
    if (l == ql && r == qr)
    {
        Ass[v] = val;
        return;
    }
    int c = (l+r)>>1;
    if (Ass[v] !=-1)
    {
        Ass[2*v] = Ass[v];
        Ass[2*v+1] = Ass[v];
        Ass[v] = -1;
    }
    if (qr<=c)
        setVal(2*v, l, c, ql, qr,val);
    else if (ql>c)
        setVal(2*v+1,c+1,r,ql,qr,val);
    else
    {
        setVal(2*v,l,c,ql,c,val);
        setVal(2*v+1,c+1,r,c+1,qr,val);
    }
}

int getVal(int v,int l,int r,int pos)
{
    if (Ass[v]!=-1)
        return Ass[v];
    if (l==r)
        return 0;
    int c = (l+r)>>1;
    if (pos<=c)
        return getVal(2*v,l,c,pos);
    return getVal(2*v+1,c+1,r,pos);
}


void run()
{
    memset(Ass,-1,sizeof(Ass));
	int n,m;
    cin>>n>>m;
    pii P[300300];
    int lastPos[300300]={0};
    int who[300300];
    memset(who,-1,sizeof(who));
    int X[300300];
    rep(i,0,m)
    {
        scanf("%d%d%d",&P[i].first, &P[i].second,X+i);
        --P[i].first;
        --P[i].second;
        --X[i];
        lastPos[X[i]] = i+1;
    }
    rep(i,0,n)
    {
        who[lastPos[X[i]]] = X[i];
    }
    int Ans[300300];
    for (int i = m; i>=0; i--)
    {
        if (i<m)
            setVal(1,0,n-1,P[i].first, P[i].second, X[i]+1);
        if (who[i]!=-1)
            Ans[who[i]] = getVal(1,0,n-1,who[i]);
    }
    rep(i,0,n)
    {
        //cout<<lastPos[i]<<endl;
        if (lastPos[i]==0)
            Ans[i] = getVal(1,0,n-1,i);
    }
    rep(i,0,n)
    printf("%d ",Ans[i]);
    puts("");
    
}


int main()
{
#ifdef _MONYURA_
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
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