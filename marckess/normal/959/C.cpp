#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;

    if (n <= 5)
    	cout << -1 << endl;
    else {
    	cout << "1 2" << endl;
    	cout << "1 " << n << endl;
    	cout << "1 " << n-1 << endl;
    	for (int i = 3; i < n-1; i++)
    		cout << "2 " << i << endl;
    }

    for (int i = 2; i <= n; i++)
    	cout << "1 " << i << endl;

    return 0;
}