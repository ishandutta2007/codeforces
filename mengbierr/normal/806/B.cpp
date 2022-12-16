#include <bits/stdc++.h>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
#define rep1(i,a,b) for (int i = a;i <= b;i++)
#define rep2(i,a,b) for (int i = a;i >= b;i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(x,y) memset(x,y,sizeof x)

typedef pair<int,int> pii;
typedef pair<LL,LL> pll;

const int dx[9] = {0,1,-1,0,0,-1,-1,1,1};
const int dy[9] = {0,0,0,-1,1,-1,1,-1,1};
const double pi = acos(-1.0);
const int N = 120+20;

int n,solves[6],a[N][6],tsolves[6];

int cal(int time,int ac,int tot)
{
    if (time==-1) return 0;
    if (2*ac>tot) return 2*(250-time);
    if (4*ac>tot) return 4*(250-time);
    if (8*ac>tot) return 6*(250-time);
    if (16*ac>tot) return 8*(250-time);
    if (32*ac>tot) return 10*(250-time);
    return 12*(250-time);
}

bool check(int k)//kcheater
{
    rep1(i,1,5) tsolves[i] = solves[i];
    rep1(i,1,5)
    {
        if (a[1][i]!=-1)//,
        {
            if (a[2][i]==-1)
            {
                //keep the ratio
            }
            else
                if (a[1][i]>a[2][i])//,AC
                //
                {
                    tsolves[i]+=k;
                }
        }
    }
    int l = 0,r = 0;
    rep1(i,1,5)
    {
        l+=cal(a[1][i],tsolves[i],n+k);
        r+=cal(a[2][i],tsolves[i],n+k);
    }
    return l>r;
}

int main()
{
    //freopen("D:\\rush.txt","r",stdin);
    ios::sync_with_stdio(false),cin.tie(0);//scanf,puts,printf not use
    cin >> n;
    rep1(i,1,n)
    {
        rep1(j,1,5)
        {
            cin >> a[i][j];
            if (a[i][j]!=-1)
                solves[j]++;
        }
    }
    rep1(i,0,n*33)
    {
        if (check(i))
        {
            cout <<i <<endl;
            return 0;
        }
    }
    cout <<-1<<endl;
    return 0;
}