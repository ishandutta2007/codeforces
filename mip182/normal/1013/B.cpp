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
ll n,x;
cin>>n>>x;
vector <ll> a(n);
rep(i,n)
cin>>a[i];
map <int,int> m;
rep(i,n)
m[a[i]]++;
rep(i,n)
{
if (m[a[i]]>1){
cout<<0;
return 0;
}
}
rep(i,n)
{
int h=x&a[i];
m[a[i]]--;
if (m[h]>0){
cout<<1;
return 0;
}
m[a[i]]++;
}
map <int,int> k;
rep(i,n)
{
int h=x&a[i];
k[h]++;
}
for (auto to:k)
{
if (to.second>1)
{
cout<<2;
return 0;
}
}
cout<<-1;}