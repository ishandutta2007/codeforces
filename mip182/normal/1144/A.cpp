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
	int n;
	cin >> n;
	REP (i,0,n)
	{
	    string s;
	    cin >> s;
	    vector <int> a;
	    REP (j,0,s.size())
	    { int t= s[j];
	      a.push_back(t);
	    }
	    sort (a.begin(),a.end());
	    if (a.size()==0)
	    cout << "YES" << endl;
	    else {
	    int answer=a[0];
	    string lol = "YES";
	    REP (k,0,a.size())
	    {
	       if (a[k]==answer) 
	        answer++;
	        else {
	       lol = "NO";
	       break;
	            
	        }
	    }
	    cout << lol << endl;
	    
	    }
	    
	    
	}
	}