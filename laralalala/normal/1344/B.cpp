#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 1005

char aa[MAXN][MAXN],a[MAXN][MAXN];
int c[MAXN],r[MAXN],cm[MAXN][2],rm[MAXN][2],mk[MAXN][MAXN];
int n,m;

void dfs(int i,int j)
{
    mk[i][j]=1;
    if(i && !mk[i-1][j] && a[i-1][j]=='#')
        dfs(i-1,j);
    if(j && !mk[i][j-1] && a[i][j-1]=='#')
        dfs(i,j-1);
    if(i<n-1 && !mk[i+1][j] && a[i+1][j]=='#')
        dfs(i+1,j);
    if(j<m-1 && !mk[i][j+1] && a[i][j+1]=='#')
        dfs(i,j+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    for(int i=0;i<MAXN;i++)
    {
        cm[i][0]=MAXN;
        rm[i][0]=MAXN;
        cm[i][1]=-1;
        rm[i][1]=-1;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='#')
            {
                r[i]++;
                rm[i][0]=min(rm[i][0],j);
                rm[i][1]=max(rm[i][1],j);
                c[j]++;
                cm[j][0]=min(cm[j][0],i);
                cm[j][1]=max(cm[j][1],i);
            }
        }

    bool ok=1;
    bool f=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(!r[i] && !c[j])
                f=1;
    for(int i=0;i<n;i++)
    {
        if(rm[i][1]!=-1)
            ok&=(r[i]==(rm[i][1]-rm[i][0]+1));
        else if(!f)
            ok=0;
    }

    for(int i=0;i<m;i++)
    {
        if(cm[i][1]!=-1)
            ok&=(c[i]==(cm[i][1]-cm[i][0]+1));
        else if(!f)
            ok=0;
    }

    if(ok)
    {
        int res=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!mk[i][j] && a[i][j]=='#')
                {
                    dfs(i,j);
                    res++;
                }
        db(res)
    }
    else
        db(-1)

    return 0;
}