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
    int t;
    cin >>t;
    REP(k,0,t)
    { string s;
      int n,answer=101;
      cin >> n;
      cin >> s;
      REP(i,0,n)
      {
         if(s[i]=='8')
         {
          answer=i+1;
          break;
             
             
         }
         
          
          
      }
      if ((n-answer)>=10 && answer!=101)
      cout << "YES"<<endl;
      else
      cout << "NO" << endl;
    } }