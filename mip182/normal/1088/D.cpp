//#define _GLIBCXX_DEBUG
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
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {

    cout<<"? 0 0"<<endl;
    int xx;
    cin>>xx;
    int ok;
    if (xx>0)
        ok=1;
    else
        ok=-1;
    if (xx==0)
    {
        int ans=0;
        for (int i=29;i>=0;i--)
        {
            cout<<"? "<<(1<<i)<<" "<<0<<endl;
            int x;
            cin>>x;
            if (x<0)
                ans|=(1<<i);
        }
        cout<<"! "<<ans<<" "<<ans<<endl;
        return 0;
    }
        int ans = 0,ans1=0;
        int xo=0,xo1=0;
        for (int i=29;i>=0;i--) {
            cout<<"? "<<((1<<i)^xo)<<" "<<((1<<i)^xo1)<<endl;
            int x;
            cin>>x;
            if (x==ok)
            {
                cout<<"? "<<((1<<i)^xo)<<" "<<xo1<<endl;
                int y;
                cin>>y;
                if (x==0)
                {
                    if (y<0)
                    {
                        ans|=(1<<i),ans1|=(1<<i),xo|=(1<<i),xo1|=(1<<i);
                    }
                }
                else
                {
                    if (x>0)
                    {
                        if (y<0)
                        {
                            ans|=(1<<i),ans1|=(1<<i),xo|=(1<<i),xo1|=(1<<i);
                        }
                    }
                    else
                    {
                        if (y<0)
                        {
                            ans|=(1<<i),ans1|=(1<<i),xo|=(1<<i),xo1|=(1<<i);
                        }
                    }
                }
            } else
            {
                if (ok>0)
                {
                   ans|=(1<<i),xo|=(1<<i);
                } else
                {
                    ans1|=(1<<i),xo1|=(1<<i);
                }
                cout<<"? "<<xo<<" "<<xo1<<endl;
                cin>>x;
                ok=x;
            }

        }
        cout<<"! "<<ans<<" "<<ans1<<endl;




}