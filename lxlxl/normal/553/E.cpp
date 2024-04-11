#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
#define inf 1e9
using namespace std;

inline void read(int &x)
{
    char c; while(!((c=getchar())>='0'&&c<='9'));
    x=c-'0';
    while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
inline void down(int &x,const int &y){if(x>y)x=y;}
const double pi = acos(-1);
const int maxn = 110;
const int maxm = 110;
const int maxt = 41000; 

struct E
{
    double x,y;
    E(){}
    E(const double _x,const double _y){x=_x;y=_y;}
}w[maxt<<1],s1[maxt<<1],s2[maxt<<1]; int id[maxt<<1],N,ln;
inline E operator +(const E &x,const E &y){return E(x.x+y.x,x.y+y.y);}
inline E operator -(const E &x,const E &y){return E(x.x-y.x,x.y-y.y);}
inline E operator *(const E &x,const E &y){return E(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x);}

void DFT(E s[],const int sig)
{
    for(int i=0;i<N;i++) if(i<id[i]) swap(s[i],s[id[i]]);

    for(int m=2;m<=N;m<<=1)
    {
        int t=m>>1,tt=N/m;
        for(int j=0;j<N;j+=m)
        {
            for(int i=0;i<t;i++)
            {
                E wn=sig==1?w[i*tt]:w[N-i*tt];
                E tx=s[j+i],ty=s[j+i+t]*wn;
                s[j+i]=tx+ty;
                s[j+i+t]=tx-ty;
            }
        }
    }
    if(sig==-1) for(int i=0;i<N;i++) s[i].x/=(double)N;
}
int n,m,T,X;
double e[maxm][maxt],f[maxn][maxt];
double p[maxm][maxt];
int u[maxm],v[maxm],ci[maxm];

int s[maxn][maxn];

void calc(const int l,const int mid,const int r)
{
    int len=r-l+1;
    N=1,ln=0; while(N<=len+r-mid) N<<=1,ln++;
    for(int i=1;i<N;i++) id[i]=(id[i>>1]>>1)|((i&1)<<ln-1);
    for(int M=2;M<=N;M<<=1)
    {
        int t=M>>1,tt=N/M;
        for(int i=0;i<t;i++) 
            w[i*tt]=E(cos(2*pi*i/M),sin(2*pi*i/M)),
            w[N-i*tt]=E(cos(2*pi*i/M),sin(-2*pi*i/M));
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<N;j++) s1[j]=s2[j]=E(0,0);
        for(int j=mid;j<=r;j++) s1[r-j]=E(f[v[i]][j],0);
        for(int j=1;j<=len;j++) s2[j]=E(p[i][j],0);
        DFT(s1,1); DFT(s2,1);
        for(int j=0;j<N;j++) s1[j]=s1[j]*s2[j];
        DFT(s1,-1);
        for(int j=l;j<mid;j++) e[i][j]+=s1[r-j].x;
    }
}
void solve(int l,int r)
{
    if(l==r) 
    {
        for(int i=1;i<n;i++) f[i][l]=s[i][n]+X;
        for(int i=1;i<=m;i++)
        {
            double temp=e[i][l]+ci[i];
            if(f[u[i]][l]>temp) f[u[i]][l]=temp;
        }
        return;
    }
    int mid=l+r+1>>1;
    solve(mid,r);
    calc(l,mid,r);
    solve(l,mid-1);
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&T,&X);
    for(int i=1;i<=m;i++) 
    {
        read(u[i]),read(v[i]),read(ci[i]);
        for(int j=1;j<=T;j++)
        {
            int x; read(x);
            p[i][j]=(double)x/100000;
        }
    }

    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) s[i][j]=inf;
    for(int i=1;i<=m;i++) s[u[i]][v[i]]=ci[i];
    for(int i=1;i<=n;i++) s[i][i]=0;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++) if(i!=k)
            for(int j=1;j<=n;j++) if(i!=j&&k!=j)
                down(s[i][j],s[i][k]+s[k][j]);
    for(int i=1;i<=n;i++) for(int j=T+1;j<=T*2;j++) f[i][j]=X+s[i][n];
    for(int i=1;i<=T;i++) f[n][i]=0;
    calc(0,T+1,2*T);

    solve(0,T);
    printf("%.9lf\n",f[1][0]);

    return 0;
}