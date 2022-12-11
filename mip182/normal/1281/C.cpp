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
        ll x;
        cin>>x;
        string s;
        cin>>s;
        string buf;
        int i=0;
        ll ans=0;
        ll now=0;
        ll remain=0;
        while (i<x&&s.size()<x)
        {
            now=(int)(s.size())-i-1;
            remain=now*((int)s[i]-'0'-1);
            int q=s.size();
            for (int f=0;f<(int)(s[i])-'0'-1;f++) {
                if (s.size()>=x)
                    break;
                for (int j = i + 1; j < q; j++) {
                    s += s[j];
                    remain--;
                    if (s.size()>=x)
                        break;
                }
            }
            i++;
        }
        //      cout<<s<<'\n';
        ans+=(int)(s.size())+remain;
        now=(int)(s.size())+remain-i-1;
        for (int j=i;j<x;j++)
        {
            ans+=now*(s[j]-'0'-1);
            now+=now*(s[j]-'0'-1);
            now--;
            ans%=mod1;
            now%=mod1;
            now+=mod1;
            now%=mod1;
        }
        cout<<ans<<'\n';


    }



}