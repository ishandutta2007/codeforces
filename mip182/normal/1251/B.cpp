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
int q;
cin>>q;
rep(jj,q)
{
int n;
cin>>n;
vector <string> s(n);
rep(i,n)
cin>>s[i];
int zero=0,one=0;
rep(i,n)
{
rep(j,s[i].size())
{
if (s[i][j]=='0')
zero++;
else
one++;
}
}
int cnt=0;
rep(i,n)
{
    if (s[i].size()%2==0)
    cnt++;
}
int k=zero%2+one%2;
if (n-cnt>=k)
cout<<n;
else
cout<<n-1;
cout<<endl;
    
    
    
}}