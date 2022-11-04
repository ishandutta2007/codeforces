// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], cn[MX];

void main_() {
	cin >> n;
	
	forn (i, n + 1)
		cn[i] = 0;
	
	forn (i, n) {
		cin >> a[i];
		cn[a[i]]++;
	}
	
	ll acu = 0;
	priority_queue<int> pq;
	
	forn (i, n + 1) {
		cout << acu + cn[i] << " ";
		
		while (cn[i]--)
			pq.push(i);
			
		if (pq.empty()) {
			while (i < n) {
				cout << -1 << " ";
				i++;
			}
		} else {
			acu += i - pq.top();
			pq.pop();
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}