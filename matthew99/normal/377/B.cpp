#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <vector>

#define REP(I,A,B) for(int I=A,_END_=B;I<=_END_;I++)
#define REPD(I,A,B) for(int I=A,_END_=B;I>=_END_;I--)
#define RI(X) X=Readint()
#define RII(X,Y) RI(X),RI(Y)
#define RIII(X,Y,Z) RI(X),RI(Y),RI(Z)
#define RS(X) scanf("%s",X)
#define RD(X) scanf("%lf",&X)
#define GCH getchar()
#define PCH(X) putchar(X)
#define MS(X,Y) memset(X,Y,sizeof(X))
#define MC(X,Y,var,len) memcpy(X,Y,sizeof(var)*(len))
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define pb(X) push_back(X)
#define mp(A,B) make_pair(A,B)
#define fr first
#define sc second
#define lch(p) (p+p)
#define rch(p) (p+p+1)
#define lowbit(X) ((X)&(-(X)))

using namespace std;

typedef pair<int,int> poi;

inline int Readint()
{
    int ret=0;
    int f=1;
    char ch;
    do
    {
        ch=GCH;
        if (ch=='-') f*=-1;
    }while(ch>=0 && (ch<'0' || ch>'9'));
    
    while ('0'<=ch && ch<='9')
    {
        ret=ret*10+ch-'0';
        ch=GCH;
    }
    return ret*f;
}

void open()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
}
void close()
{
    fclose(stdin);
    fclose(stdout);
}

const int MAXN =  1e5+10;
poi h[MAXN];

poi a[MAXN];
poi b[MAXN];
int c[MAXN];

int ans[MAXN];

int n,m,s;

bool cmp(int x,int y)
{
    return a[x]<a[y];
}

void init()
{
    RIII(n,m,s);
    REP(i,1,m) RI(a[i].fr),a[i].sc=i;
    REP(i,1,n) RI(b[i].fr),b[i].sc=i;
    REP(i,1,n) RI(c[i]);
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
}

bool check(int t)
{
    int p=0;
    for (int i=m,j=n,res=s;i;)
    {
        while (j && b[j].fr>=a[i].fr)
        {
            h[p++]=mp(-c[b[j].sc],b[j].sc);
            push_heap(h,h+p);
            j--;
        }
        if (!p) return 0;
        res+=h[0].fr;
        if (res<0)
            return 0;
        else 
        {
            for (int u=t;u && i;i--,u--) ans[a[i].sc]=h[0].sc;
            pop_heap(h,h+p--);
        }
    }
    return 1;
}

void work()
{
    int l=1,r=100000;
    int mid;
    int answer=-1;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (check(mid))
        {
            r=mid-1;
            answer=mid;
        }
        else
            l=mid+1;
    }
    if (answer==-1)
    {
        printf("NO");
    }
    else
    {
        printf("YES\n");
        check(answer);
        REP(i,1,m) printf("%d ",ans[i]);
    }
}

int main()
{
    int _=0;
    init();
    work();
    close();
    return 0;
}