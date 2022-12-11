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
	ll q;
	cin >>q;
	for (ll k=0;k<q;k++)
	{
	 ll n;
	 cin >> n;
	 vector <ll> a(n,0);
	 for (ll i=0;i<n;i++)
	 {
	  ll x;
	  cin >> x;
	  a[x-1]=a[x-1]+1;
	 }
	 sort(a.begin(),a.end());
	 ll answer=0,chet=1000000*2+1, kek=1000000*2+1;
	 for (ll j=n-1;j>=0;j--){
	  if (chet>a[j] && a[j]>0)
	  chet=a[j];
	  if (a[j]>=chet && chet>0)
	  {
	    answer+=chet;
	    chet--;
	  }
	 }
	  cout << answer<< endl;
	  
	  
	  
	  
	  
	 }}