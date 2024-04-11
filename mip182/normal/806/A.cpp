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
int t;
cin>>t;
rep(jj,t)
{
  ll x,y,p,q;
  cin>>x>>y>>p>>q;
  if (p==q)
  {
  if (x!=y)
  cout<<-1<<endl;
  else
  cout<<0<<endl;
  continue;
  }
  if (p==0)
  {
  if (x==0)
  cout<<0<<endl;
  else
  cout<<-1<<endl;
  continue;
  }
  ll g=(x+p-1)/p;
  ll s=(y-x+q-p-1)/(q-p);
  cout<<q*max(g,s)-y<<endl;
}}