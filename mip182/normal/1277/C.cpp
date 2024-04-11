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
        string s;
        cin>> s;
        vector <int> ans;
        for (int i=0;i<(int)s.size()-2;i++)
        {
            if (s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')
            {
                bool ok= false;
                if (4+i<(int)s.size())
                {
                    if (s[i+3]=='n'&&s[i+4]=='e')
                        ok=true;
                }
                if (ok)
                {
                    ans.pb(i+2);
                    i+=4;
                    continue;
                }
                else
                {
                    ans.pb(i+1);
                    i++;
                    continue;
                }
            }
            if (s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')
            {
                ans.pb(i+1);
                i+=2;
                continue;
            }

        }
        cout<<ans.size()<<'\n';
        for (int i=0;i<ans.size();i++)
            cout<<ans[i]+1<<" ";
        cout<<'\n';

    }






}