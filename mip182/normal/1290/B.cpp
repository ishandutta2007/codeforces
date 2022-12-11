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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    string s;
    cin>>s;
    int n=s.size();
    vector <vector <int> > pref(s.size()+1);
    vector <int> c(26,0);
    pref[0]=c;
    for (int i=0;i<n;i++)
    {
        c[s[i]-'a']++;
        pref[i+1]=c;
    }
    int q;
    cin>>q;
    while (q--)
    {
        int l,r;
        cin>>l>>r;
        if (l==r) {
            cout << "Yes" << '\n';
            continue;
        }
        vector <int> b=pref[r];
        for (int i=0;i<26;i++)
            b[i]-=pref[l-1][i];
        bool ok=false;
        for (int i=0;i<26;i++)
        {
            if (b[i]==r-l+1)
                ok=true;
        }
        if (ok)
            cout<<"No\n";
        else {
            int cnt=0;
            for (int i=0;i<26;i++)
            {
                if (b[i]>0)
                    cnt++;
            }
            if (cnt>2)
            {
                cout<<"Yes\n";
                continue;
            }
            if (s[l-1]==s[r-1])
                cout<<"No\n";
            else
                cout<<"Yes\n";
        }
      //  cout<<'\n';

    }




}