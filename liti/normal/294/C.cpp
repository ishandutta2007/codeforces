//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000 + 10; 
const int mod = 1e9 + 7; 

inline int mul(int a, int b) { 
	return 1ll * a * b % mod; 
}
inline int sum(int a, int b) { 
	int c = a + b; 
	if( c >= mod ) {
		c -= mod;
	}
	return c; 
}

int a[maxN]; 
int tav[maxN];
int c[maxN][maxN];

int main() { 
	tav[0] = 1; 
	for(int i = 1; i < maxN; i++)
		tav[i] = sum(tav[i-1], tav[i-1]);
	
	c[0][0] = 1; 
	for(int i = 1; i < maxN; i++) { 
		c[i][0] = 1; 
		for(int j = 1; j < maxN; j++)
			c[i][j] = sum(c[i-1][j-1], c[i-1][j]); 
	}
	
	int n, m;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++) { 
		cin >> a[i];
		a[i]--;
	}
	sort(a, a + m);
	a[m] = n;
	
	int last = -1;
	int sum = 0; 
	int ans = 1;
	for(int i = 0; i <= m; i++) {
		int v = a[i] - last - 1; 
		if( v > 1 && i != 0 && i != m ) 
			ans = mul(ans, tav[v-1]);
		
		ans = mul( ans, c[sum+v][v] ); 
		sum += v;
		last = a[i];
	}
	cout << ans << endl;
}