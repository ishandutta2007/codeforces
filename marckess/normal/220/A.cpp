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

int n, a[100005];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    	cin >> a[i];

    for (int i = 0; i < n-1; i++) {
    	if (a[i] > a[i+1]) {
    		for (int j = i+1; j < n-1; j++) {
    			if (a[j] > a[j+1]) {
    				int d = i;
    				while (d >= 0 && a[i] == a[d])
    					d--;
    				d++;
    				swap(a[d], a[j+1]);

    				for (int l = 0; l < n-1; l++) {
    					if (a[l] > a[l+1]) {
    						cout << "NO" << endl;
    						return 0;
    					}
    				}

    				cout << "YES" << endl;
    				return 0;
    			}
    		}

    		int j = i+1;
    		while (j < n && a[j] == a[i+1])
    			j++;
    		j--;

    		int d = i;
    		while (d >= 0 && a[i] == a[d])
    			d--;
    		d++;

    		swap(a[d], a[j]);
    		for (int i = 0; i < n-1; i++) {
    			if (a[i] > a[i+1]) {
    				cout << "NO" << endl;
    				return 0;
    			}
    		}

    		cout << "YES" << endl;
    		return 0;
    	}
    }

    cout << "YES" << endl;

    return 0;
}