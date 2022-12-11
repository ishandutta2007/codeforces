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

int main() {
mipletsplay;
ll n,p,w,d;
cin>>n>>p>>w>>d;
ll x=w-d;
if (p%(__gcd(w,d)))
{
cout<<-1;
return 0;
}
for (ll i=0;i<=(p-n*w)/(d-w);i++)
{
if ((p-i*d)%w==0)
{
ll u=(p-i*d)/w;
if (u>=0&&i+u<=n){
cout<<u<<" "<<i<<" "<<n-i-u;
return 0;
}
else
break;
}
}
cout<<-1;}
/*
xw+yd=p;
x+y<=n;
p=xw+yd<=yd+nw-wy
p-nw<=y(d-w)

*/