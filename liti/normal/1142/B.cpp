//be naame khodaa
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = 2*100*1000 + 100;
const int L = 20; 

int nex[N][L];
int rmq[N][L]; 
int lg[N];

int p[N], mp[N], a[N];

int last[N]; 

int main(){
	ios::sync_with_stdio(false); cin.tie(0); 

	int n, m, q;
	cin >> n >> m >> q; 

	for(int i = 0; i < n; i++) { 
		cin >> p[i];
		p[i]--; 
		mp[p[i]] = i; 
	}

	for(int i = 0; i < m; i++) { 
		cin >> a[i]; 
		a[i] = mp[a[i]-1]; 
		//cerr << a[i] << ' ';
	}
	//cerr << endl;

	for(int k = 0; k < L; k++) 
		nex[m][k] = m; 

	fill(last, last + n, m); 
	for(int i = m-1; i >= 0; i--) { 
		nex[i][0] = last[(a[i]+1)%n]; 
		//cerr << "~ " << i << " " << nex[i][0] << endl;
		for(int k = 1; k < L; k++) 
			nex[i][k] = nex[nex[i][k-1]][k-1]; 
		last[a[i]] = i; 
	}

	lg[1] = 0; 
	for(int i = 2; i < N; i++) 
		lg[i] = lg[i/2] + 1;

	for(int i = m-1; i >= 0; i--) { 
		int v = n-1;
		int x = i; 
		for(int k = 0; k < L; k++) 
			if( (v>>k) & 1 ) 
				x = nex[x][k]; 
		//cerr << "For i " << i << " : " << x << endl;
		rmq[i][0] = x; 

		for(int k = 1; k < L; k++) 
			if( i + (1<<k) <= m ) 
				rmq[i][k] = min(rmq[i][k-1], rmq[i+(1<<(k-1))][k-1]); 
	}

	for(int i = 0; i < q; i++) { 
		int l, r;
		cin >> l >> r; 
		l--; 

		int len = lg[r-l]; 

		int v = min( rmq[l][len], rmq[r-(1<<len)][len] ); 

		//cerr << v << " " << r << endl;
		cout << (v < r) ; 
	}

	cout << endl;

    return 0;
}