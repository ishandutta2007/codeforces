#include<bits/stdc++.h>
  
using namespace std;
  
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
const double eln = 2.718281828459045235360287471352;
 
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "[%s] " fmt "\n", \
    __func__, ##__VA_ARGS__)
#else
# define _debug(...) ((void) 0)
#endif
 
#define IN freopen("sample.in", "r", stdin)
#define OUT freopen("sample.out", "w", stdout)
#define scd(x) scanf("%d", &x)
#define scld(x) scanf("%lld", &x)
#define scs(x) scanf("%s", x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define prcas printf("Case #%d: ", cas)
#define pncas printf("Case #%d:\n", cas)
#define lowbit(x) ((x) & (-x))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
 
int m;
pii pre[8][15][305][305],ans[8];
char f[8][15][305][305];
void ot(int s,int src,int a,int b)
{
    if (s==0) return;
    ans[s]=pre[s][src][a][b];
    ot(s-1,src+(pre[s][src][a][b].fi>pre[s][src][a][b].se?-1:1),a-pre[s][src][a][b].fi,b-pre[s][src][a][b].se);
}
int main()
{
    f[0][3][0][0]=1;
    for (int s=0;s<5;++s)
	for (int src=-2;src<=2;++src)
        for (int a=0;a<=200;++a)
            for (int b=0;b<=200;++b)
	    if (f[s][src+3][a][b]&&(s+src)/2<3&&(s-src)/2<3)
            {
                if (a+(s==4?15:25)<=200)
                    for (int i=0;i<=(s==4?13:23)&&b+i<=200;++i)
                    if (f[s+1][src+3+1][a+(s==4?15:25)][b+i]==0)
                        f[s+1][src+3+1][a+(s==4?15:25)][b+i]=1,
                        pre[s+1][src+3+1][a+(s==4?15:25)][b+i]=mp((s==4?15:25),i);
                for (int i=(s==4?16:26);a+i<=200&&b+i-2<=200;++i)
                    if (f[s+1][src+3+1][a+i][b+i-2]==0)
                        f[s+1][src+3+1][a+i][b+i-2]=1,
                        pre[s+1][src+3+1][a+i][b+i-2]=mp(i,i-2);
                if (b+(s==4?15:25)<=200)
                    for (int i=0;i<=(s==4?13:23)&&a+i<=200;++i)
                    if (f[s+1][src+3-1][a+i][b+(s==4?15:25)]==0)
                        f[s+1][src+3-1][a+i][b+(s==4?15:25)]=1,
                        pre[s+1][src+3-1][a+i][b+(s==4?15:25)]=mp(i,(s==4?15:25));
                for (int i=(s==4?16:26);a+i-2<=200&&b+i<=200;++i)
                    if (f[s+1][src+3-1][a+i-2][b+i]==0)
                        f[s+1][src+3-1][a+i-2][b+i]=1,
                        pre[s+1][src+3-1][a+i-2][b+i]=mp(i-2,i);
            }
    for (scanf("%d",&m);m;--m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (f[3][6][a][b])
        {
            puts("3:0");
            ot(3,6,a,b);
            for (int i=1;i<=3;++i)
                printf("%d:%d%c",ans[i].fi,ans[i].se," \n"[i==3]);
        }
        else if (f[4][5][a][b])
        {
            puts("3:1");
            ot(4,5,a,b);
	    for (int i=1;i<=4;++i)
                printf("%d:%d%c",ans[i].fi,ans[i].se," \n"[i==4]);
        }
        else if (f[5][4][a][b]||f[5][2][a][b])
        {
            puts(f[5][4][a][b]?"3:2":"2:3");
            ot(5,f[5][4][a][b]?4:2,a,b);
	    for (int i=1;i<=5;++i)
                printf("%d:%d%c",ans[i].fi,ans[i].se," \n"[i==5]);
        }
        else if (f[4][1][a][b])
        {
            puts("1:3");
            ot(4,1,a,b);
	    for (int i=1;i<=4;++i)
                printf("%d:%d%c",ans[i].fi,ans[i].se," \n"[i==4]);
        }
        else if (f[3][0][a][b])
        {
            puts("0:3");
            ot(3,0,a,b);
	    for (int i=1;i<=3;++i)
                printf("%d:%d%c",ans[i].fi,ans[i].se," \n"[i==3]);
        }
        else puts("Impossible");
    }
    return 0;
}