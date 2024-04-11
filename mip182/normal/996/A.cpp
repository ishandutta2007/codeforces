#include <bits/stdc++.h>
typedef long long ll;

#define PB push_back
#define EB emplace_back 
#define MP make_pair 
#define F first
#define S second
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define mipletsplay ios_base::sync_with_stdio(0); cin.tie(0); 
#define REP(i, a, b) for (int i = a; i < b; i++)


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const int INF = 1e9;

int main() {
	mipletsplay;
    ll n,sto=0,dvas=0,des=0,pyat=0,odin=0;
    cin >>n;
    while (n>=100)
    {
      sto++;
      n-=100;
        
        
    }
    while (n>=20)
    {
      dvas++;
      n-=20;
        
        
    }
    while (n>=10)
    {
      des++;
      n-=10;
        
        
    }
    while (n>=5)
    {
      pyat++;
      n-=5;
        
        
    }
    while (n>0)
    {
      odin++;
      n-=1;
        
        
    }
    
    cout << odin+pyat+des+dvas+sto; }