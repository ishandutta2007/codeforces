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
int n,m;
cin>>n>>m;
int cnt=0;
vector <int> a(n,0);
for (int i=0;i<m;i++)
{
int x;
cin>>x;
x--;
if (a[x]){
a[x]++;
cout<<0;
}
else
{
cnt++;
a[x]++;
if (cnt==n)
{
cout<<1;
cnt=0;
for (int j=0;j<n;j++)
{
a[j]--;
if (a[j])
cnt++;
}
}
else
cout<<0;
}
}}