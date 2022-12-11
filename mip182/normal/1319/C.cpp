#include <bits/stdc++.h>
//#pragma GCC optmize("O3,Ofast,unroll-loops,fast-math,no-stack-protector")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<(n);i++)
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vi vector <int>
#define vvi vector <vector <int> >
#define vll vector <ll>
#define fi first
#define se second
#define mii map <int,int>
#define mll map <ll,ll>
#define si set <int>
#define sll set <ll>
#define pb push_back

const int MAXN=1e6+100;
const ll INF=1e9;
const ll INFLL=1e18;
const ll mod1=1e9+7;


signed  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    int n;
    cin>>n;
    string s;
    cin>>s;
    while (true)
    {
        bool ok=false;
      //  cout<<s<<'\n';
        int mx=0;
        for (int j=0;j<s.size();j++)
            mx=max(mx,s[j]-'a');
        while (mx>=0) {
            for (int j = 0; j < s.size(); j++) {
                if (s[j] - 'a' == mx) {
                    if (j != 0 && s[j - 1] == s[j] - 1)
                        ok = true;
                    if (j != (int) (s.size()) - 1 && s[j + 1] == s[j] - 1)
                        ok = true;
                    if (ok) {
                        string t = "";
                        for (int i = 0; i < j; i++)
                            t += s[i];
                        for (int i = j + 1; i < s.size(); i++)
                            t += s[i];
                        s = t;
                        break;
                    }
                }
            }
            if (ok==true)
                break;
            else
                mx--;
        }
        if (ok==false)
            break;
    }
    cout<<n-(int)(s.size());


}