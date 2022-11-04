#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

string s;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> s >> s;

    s = "0" + s + "0";

    if (s.find("000") != string::npos || s.find("11") != string::npos)
    	cout << "No" << endl;
    else
    	cout << "Yes" << endl;

    return 0;
}