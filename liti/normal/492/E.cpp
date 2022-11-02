/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000*1000 + 10; 

int a[maxN], b[maxN];
int c[maxN];

int cnt[maxN];

int main() { 
	int n,m,dx,dy;
	cin >> n >> m >> dx >> dy;

	int tmp = dx;
	for( int i = n - 1 ; i >= 0 ; i-- ) {
		c[tmp] = i;
		tmp = (tmp+dx)%n;
	}
	assert(c[0]==0);

	tmp = dy;
	for( int i = 0 ; i < n ; i++ ) {
		a[i] = tmp;
		b[tmp] = i;
		tmp = (tmp+dy)%n;
	}

	for( int i = 0 ; i < m ; i++ ){ 
		int x,y;
		cin >> x >> y;
		cnt[ a[(b[y]+c[x])%n] ]++;
	}

	cout << 0 << ' ' << max_element( cnt , cnt + n  ) - cnt << endl;
}