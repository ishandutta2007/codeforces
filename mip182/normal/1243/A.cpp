#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>k;
    while (k--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        rep(i,n)
        cin>>a[i];
        sort(all(a));
        reverse(all(a));
        int cnt=1;
        while (cnt<=n&&a[cnt-1]>=cnt)
            cnt++;
        cout<<cnt-1<<'\n';
    }
}