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

 
int main() {
mipletsplay;
int n;
cin>>n;
ll q=0;
ll a[n][n];
for (int i=0;i<n;i+=2)
{
for (int j=0;j<n;j++)
a[i][j]=q+j+1;
q+=2*n;
}
ll f=2*n;
for (int i=1;i<n;i+=2)
{
for (int j=0;j<n;j++)
a[i][j]=f-j;
f+=2*n;
}
for (int i=0;i<n;i++)
{
for (int j=0;j<n;j++)
cout<<a[j][i]<<" ";
cout<<endl;
}}