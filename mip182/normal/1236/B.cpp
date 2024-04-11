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


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod=1e9+7;
ll binpow(ll a, ll b)
{
if (b==0)
return 1;
if (b%2==1)
return (((binpow(a,(b-1)/2)*binpow(a,(b-1)/2))%mod)*(a%mod))%mod;
else
return ((binpow(a,b/2)%mod)*(binpow(a,b/2)%mod))%mod;
    
}

int main() {
mipletsplay;
ll n,m;
cin>>n>>m;
cout<<binpow(binpow(2,m)-1,n);}