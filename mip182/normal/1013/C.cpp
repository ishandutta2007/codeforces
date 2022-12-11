#include <bits/stdc++.h>
typedef long long ll;
#define podotrezok(i,j) substr(i-1,j)
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


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;

int main() {
mipletsplay;
ll n;
cin>>n;
vector <ll > a(2*n);
rep(i,n*2)
cin>>a[i];
sort(a.begin(),a.end());
ll ans=INFLL;
ll minix=INFLL;
rep(i,n-1)
{
ans=min(ans,(a[i+n]-a[i+1])*(a[2*n-1]-a[0]));
}
ans=min(ans,(a[n-1]-a[0])*(a[2*n-1]-a[n]));
ans=min(ans,(a[n]-a[0])*(a[2*n-1]-a[n-1]));
cout<<ans;}