#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0);
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define sz(x) (int)x.size()

using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod=1e9+7;

ll power(ll x, ll y) 
{ 
    ll res = 1;  
   
    while (y > 0) 
    { 
        if (y & 1) {
            res = ((res)%mod)*(x%mod); 
            res%=mod;
        }
   
        y = y>>1; 
        x = (x%mod)*(x%mod); 
        x%=mod;
    } 
    return res; 
}

int main() {
mipletsplay;
ll n,m;
cin>>n>>m;
ll a[100001];
a[0]=0;
a[1]=1;
a[2]=2;
for (int i=3;i<100001;i++)
{
a[i]=((a[i-1]%mod)+(a[i-2]%mod))%mod;
}
ll ans=0;
if (n==1||m==1)
cout<<(a[max(n,m)]*2)%mod;
else
{
cout<<((a[n]+a[m]-1)*2)%mod;
}
}