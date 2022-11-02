#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
#define x first
#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}

int INF=1e9;
pii none=pii(-1,-1);
struct vert
{
    bool close;
    int dst;
    vert()
    {
        close=false;
        dst=INF;
    }

} g[1001][1001][4];

pii Inc[1001][1001][4];

void coni(pii l,pii r)
{
    Inc[l.x][l.y][1]=r;
    Inc[r.x][r.y][3]=l;
}

void conj(pii u,pii d)
{
    Inc[u.x][u.y][2]=d;
    Inc[d.x][d.y][0]=u;
}

struct index
{
    si i,j,d;
    int dist;
    index(){}
    index(si i0,si j0,si d0,int dst)
    {
        i=i0;
        j=j0;
        d=d0;
        dist=dst;
    }
};

bool operator<(const index &a,const index &b)
{
     return a.dist>b.dist;
   
}

void run()
{
    int n,m;
    char M[1001][1001];
    int N[1001][1001];
    cin>>n>>m;
    rep(i,0,n)
        scanf(" %s",M[i]);
    memset(N,-1,sizeof(N));
    if (n==1)
    {
        printf("0\n");
        return;
    }
    rep(i,0,n)
        rep(j,0,m)
            rep(d,0,4)
                Inc[i][j][d]=none;
    rep(i,0,n)
    {
        int c=-1;
        rep(j,0,m)
            if (M[i][j]=='.')
            {   
                if (i!=0) N[i][j]=N[i-1][j];
            }
            else
            {
                if (c!=-1)
                    coni(pii(i,c),pii(i,j));
                if (i!=0 && N[i-1][j]!=-1)
                    conj(pii(N[i-1][j],j),pii(i,j));
                c=j;
                N[i][j]=i;
            }
    }
    int f=-1;
    rep(j,0,m)
        if (M[n-1][j]=='#')
            f=j;
    int s=-1;
    rep(j,0,m)
        if (M[0][j]=='#')
        {s=j;break;}
    if (s==-1 || f==-1)
    {
        printf("-1\n");
        return;
    }
    g[n-1][f][1].dst=0;
    priority_queue<index> pq;
    pq.push(index(n-1,f,1,0));
    index c;
    int To[4]={2,3,0,1};
    pii nei;
    while (!pq.empty())
    {
        c=pq.top();
        pq.pop();
        if (g[c.i][c.j][c.d].close) continue;
        g[c.i][c.j][c.d].close=true;
        if (g[0][s][1].close && g[0][s][2].close) break;
        rep(k,0,4)
            if ((nei=Inc[c.i][c.j][k])!=none)
            {
                int cost=0;
                if ((k^c.d)&1) cost=1;
                if (!g[nei.x][nei.y][To[k]].close && g[nei.x][nei.y][To[k]].dst>cost+g[c.i][c.j][c.d].dst)
                {
                    g[nei.x][nei.y][To[k]].dst=cost+g[c.i][c.j][c.d].dst;
                    pq.push(index(nei.x,nei.y,To[k],g[nei.x][nei.y][To[k]].dst));
                }
            }
    }
    int res=min(g[0][s][1].dst,g[0][s][2].dst+1);
    if (res>=INF) printf("-1\n");
    else printf("%d\n",res);

}

int main()
{
    //freopen("in.txt","w",stdout);
    //puts("1000 1000");
    //rep(i,0,1000)
    //{
    //  rep(j,0,1000)
    //      printf("%c",(i==0 && j!=2?'.':'#'));
    //  puts("");
    //}
    //return 0;
#ifdef _MON_JUDGE_
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif
    time_t beg=clock();
    run();
#ifdef _MON_JUDGE_
    puts("=================");
    printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}

/*

*/