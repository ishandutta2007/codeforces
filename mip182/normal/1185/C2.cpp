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
ll n,m;
cin>>n>>m;
vector <ll> t(101,0);
ll sum=0;
rep(i,n)
{
ll x;
cin>>x;
ll u=sum;
ll cnt=0;
ll j=100;
while (m-u+t[j]*j<x)
{
u-=t[j]*j;
cnt+=t[j];
j--;
}
if (j>0&&m-u<x)
{
cnt+=(x+u-m+j-1)/j;
}
cout<<cnt<<" ";
t[x]++;
sum+=x;


}}