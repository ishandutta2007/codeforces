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
	string s,t;
	cin >> s;
	cin >> t;
	if (s.size()!=t.size())
	cout << "NO";
	else {
	 int a=0,b=0,i=0;
	 while (a==b && a<1001){
	   if (s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
	   a++;
	   if (t[i]=='a' ||t[i]=='e' ||t[i]=='i' ||t[i]=='o' ||t[i]=='u')
	   b++;
	   i++;
	 }
	 if (i>s.size())
	 cout << "YES";
	 else
	 cout << "NO";
	 
	    
	    
	}}