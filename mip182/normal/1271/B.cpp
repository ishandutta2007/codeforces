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
    int n;
    cin>>n;
    int cntb=0,cntw=0;
    string s;
    cin>>s;
    string t=s;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='W')
            cntw++;
        else
            cntb++;
    }
    vector <int> ans;
    for (int i=0;i<n-1;i++)
    {
        if (s[i]=='B') {
            ans.pb(i);
            s[i]='B'+'W'-s[i];
            s[i+1]='B'+'W'-s[i+1];
        }
    }
    if (s[n-1]=='W') {
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] + 1 << ' ';
    }
    else {
        ans.clear();
        vector <int> ans;
        for (int i=0;i<n-1;i++)
        {
            if (t[i]=='W') {
                ans.pb(i);
                t[i]='B'+'W'-t[i];
                t[i+1]='B'+'W'-t[i+1];
            }
        }
        if (t[n-1]=='B')
        {
            cout<<ans.size()<<'\n';
            for (int i=0;i<ans.size();i++)
                cout<<ans[i]+1<<" ";

        }
        else
            cout<<-1;
    }
    cout<<'\n';
}