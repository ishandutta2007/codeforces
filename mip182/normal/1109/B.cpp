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
#define vvll vector <vll>
#define vsi vector <si>
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
    vector <int> cnt(26);
    for (int i=0;i<n;i++)
        cnt[s[i]-'a']++;
    for (int i=0;i<26;i++)
    {
        if (cnt[i]==n||(n%2==1&&cnt[i]==n-1))
        {
            cout<<"Impossible";
            return 0;
        }
    }
    string ss;
    for (int i=0;i<n-1;i++) {
        ss += s[i];
        string sss;
        for (int j = i + 1; j < n; j++)
            sss += s[j];
        sss += ss;
        bool ok = true;
        for (int j = 0; j < sss.size()/2; j++) {
            if (sss[j] != sss[(int)sss.size() - 1 - j])
                ok = false;
        }
        if (ok&&sss!=s) {
            cout << 1;
            return 0;
        }
    }
    cout<<2;


}