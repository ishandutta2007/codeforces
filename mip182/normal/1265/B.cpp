#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define fi first
#define se second
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector <int> p(n);
        vector <int> a(n);
        rep(i,n) {
            cin >> p[i];
            p[i]--;
            a[p[i]]=i;
        }
        int i=a[0],j=a[0];
        cout<<1;
        for (int f=2;f<=n;f++)
        {
            int b=a[f-1];
            if (b>j)
            {
                while (b>j)
                    j++;
            }
            if (b<i)
            {
                while (b<i)
                    i--;
            }
            if (j-i+1==f)
                cout<<1;
            else
                cout<<0;
        }
        cout<<'\n';

    }
}