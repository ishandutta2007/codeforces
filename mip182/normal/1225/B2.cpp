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
int t;
cin>>t;
rep(jj,t)
{
ll n,k,d;
cin>>n>>k>>d;
vector <ll> a(n);
rep(i,n)
cin>>a[i];
int ans=INF;
int i=0,j=0;
int cnt=0;
mii m;
while (i<=n-d)
{
while (j-i!=d)
{
if (m[a[j]]==0)
{
    m[a[j]]++;
    cnt++;
}
else
{
 m[a[j]]++;   
}
j++;
}
ans=min(ans,cnt);
if (m[a[i]]==1)
{
    cnt--;
}
m[a[i]]--;
i++;
}
cout<<ans<<'\n';

    
    
    
}}