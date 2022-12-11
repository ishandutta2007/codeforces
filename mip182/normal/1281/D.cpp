#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int r,c;
        cin>>r>>c;
        vector <string> a(r);
        bool ok=true;
        for (int i=0;i<r;i++)
        {
            cin>>a[i];
        }
        int mostl=INF,mostr=-1,mostu=-1,mostd=INF;
        int ml=INF,mr=-1,mu=-1,md=INF;
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                if (a[i][j]=='A') {
                    ok = false;
                    md=min(md,i);
                    mu=max(mu,i);
                    ml=min(ml,j);
                    mr=max(mr,j);
                }
                else
                {
                    mostd=min(mostd,i);
                    mostu=max(mostu,i);
                    mostl=min(mostl,j);
                    mostr=max(mostr,j);
                }
            }
        }
        if (ok)
        {
            cout<<"MORTAL"<<'\n';
            continue;
        }
        int ans=4;
        string check="";
        for (int i=0;i<c;i++)
            check+='A';
        if (mostr==-1)
        {
            ans=min(ans,0);
        }
        if (mostr!=c-1||mostl!=0||mostu!=r-1||mostd!=0)
        {
            ans=min(ans,1);
        }
        for (int i=0;i<r;i++)
        {
            if (a[i]==check)
                ans=min(ans,2);
        }
        for (int i=0;i<c;i++)
        {
            bool ko=true;
            for (int j=0;j<r;j++)
            {
                if (a[j][i]=='P')
                {
                    ko=false;
                    break;
                }
            }
            if (ko)
                ans=min(ans,2);
        }
        if (a[0][0]=='A')
            ans=min(ans,2);
        if (a[r-1][c-1]=='A')
            ans=min(ans,2);
        if (a[0][c-1]=='A')
            ans=min(ans,2);
        if (a[r-1][0]=='A')
            ans=min(ans,2);
        for (int i=1;i<c-1;i++)
        {
            if (a[0][i]=='A')
                ans=min(ans,3);
            if (a[r-1][i]=='A')
                ans=min(ans,3);
        }
        for (int i=1;i<r-1;i++)
        {
            if (a[i][0]=='A')
                ans=min(ans,3);
            if (a[i][c-1]=='A')
                ans=min(ans,3);
        }
        cout<<ans<<'\n';

    }



}