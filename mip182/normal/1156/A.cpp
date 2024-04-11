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

int main() {
mipletsplay;
int n;
cin>>n;
vi a(n);
rep(i,n)
cin>>a[i];
bool ok=true;
int ans=0;
for (int i=1;i<n;i++)
{
if (a[i]==a[i-1]||((a[i]==2&&a[i-1]==3)||(a[i-1]==2&&a[i]==3)))
ok=false;
if (a[i-1]==1)
ans+=a[i]+1;
else
{
if (a[i-1]==2)
ans+=3;
else
ans+=4;
}
}
for (int i=2;i<n;i++)
{
if (a[i-2]==3&&a[i-1]==1&&a[i]==2)
ans-=1;
}
if (ok)
{
    cout<<"Finite"<<'\n';
    cout<<ans;
}
else
cout<<"Infinite";}