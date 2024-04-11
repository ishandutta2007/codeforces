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

int main() {
mipletsplay;
ll n;
cin>>n;
string s;
cin>>s;
ll ans=0;
ll r,l;
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
{
string t=s;
char a=t[i];
char b=t[j];
t[i]=b;
t[j]=a;
ll pref[n+1];
pref[0]=0;
for (int i=0;i<n;i++)
{
if (t[i]=='(')
pref[i+1]=pref[i]+1;
else
pref[i+1]=pref[i]-1;
}
ll minix=INF;
ll cnt=0;
for (int i=1;i<=n;i++)
{
if (pref[i]<minix)
{
minix=pref[i];
cnt=1;
}
else
{
if (pref[i]==minix)
cnt++;
}
}
if (pref[n]==0)
{
if (ans<cnt)
{
ans=cnt;
r=i;
l=j;

}
}

}
}
cout<<ans<<endl;
if (ans==0)
cout<<1<<" "<<1;
else
cout<<l+1<<" "<<r+1;}