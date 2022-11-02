/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int mod = 1e9 + 7;
const int maxN = 3000*100 + 10; 
const int maxL = 20; 

int val[maxL][3][maxN];
pair<ll,pair<int,int>> tmp[maxN]; 
string a[3];

void do_suffix() {
	for( int k = 0 ; k < 3 ; k++ ) 
		for( int i =0 ; i < sz(a[k]) ; i++ ) 
			val[0][k][i] = a[k][i];

	for( int k = 1 ; k < maxL ; k++ ) {
		int cnt = 0; 
		for( int t = 0 ; t < 3 ; t++ ) 
			for( int i = 0 ; i < sz(a[t]); i++ ) 
				tmp[cnt++] = {val[k-1][t][i]*ll(maxN) + val[k-1][t][min(i+(1<<(k-1)),sz(a[t]))] , {t , i} } ; 
		sort( tmp , tmp + cnt ) ; 
		int num = 1;
		for( int i =  0 ; i < cnt ; i++ ) {
			if( i && tmp[i].first != tmp[i-1].first ) 
				num++;
			val[k][tmp[i].second.first][tmp[i].second.second] = num;
		}
	}
//	for( int i = 0 ;i < 3 ; i++ ) 
//		for( int j = 0 ; j < sz( a[i] ) ; j++ ) 
//			cout << a[i].substr( j , sz(a[i]) - j ) << ' ' << val[maxL-1][i][j] << '\n';
}

pair<int,int> lcp[maxN];

int par[maxN];
int cnt[3][maxN];
int h[maxN];

ll ans[maxN];

void relax( int u , int nh ) { 
	ll val = cnt[0][u] * ll( cnt[1][u] ) % mod * cnt[2][u];
	val %= mod;
	ans[nh] += val;
	ans[nh] %= mod;
	ans[h[u]] += mod - val;
	ans[h[u]] %= mod;
}

int dFind( int u ) { 
	return par[u] == -1 ? u : par[u] = dFind( par[u] ) ; 
}

void dMerge( int u , int v , int nh ) { 
	u = dFind(u), v = dFind(v); 
	relax( u , nh ) ; 
	relax( v , nh ) ; 
	par[v] = u;
	for( int i = 0 ; i < 3 ; i++ ) 
		cnt[i][u] += cnt[i][v];
	h[u] = nh;
}

int main() { 
	memset(par,-1,sizeof par);
	cin >> a[0] >> a[1] >> a[2] ; 
	do_suffix(); 
	int n = sz(a[0]) + sz(a[1]) + sz(a[2]);

	for( int i = 0 ; i < n - 1 ; i++ ) { 
		int t1 = tmp[i].second.first, i1 = tmp[i].second.second;
		int t2 = tmp[i+1].second.first , i2 = tmp[i+1].second.second;
		lcp[i].second = i;
		if( val[maxL-1][t1][i1] == val[maxL-1][t2][i2] ) { 
			lcp[i].first = sz(a[t1]) - i1;
			continue;
		}

		for( int k = maxL - 1 ; k >= 0 ; k -- ) 
			if( val[k][t1][i1] == val[k][t2][i2] ) {
				i1 = i1 + (1<<k);
				i2 = i2 + (1<<k); 
				lcp[i].first += (1<<k);
			}
	}

	for( int i = 0 ; i < n ; i++ ) {
		cnt[tmp[i].second.first][i]++;
		h[i] = sz(a[tmp[i].second.first]) - tmp[i].second.second;
	}
	sort( lcp , lcp + n - 1, greater<pair<int,int>>() ) ; 

	for( int i = 0 ; i < n - 1 ; i++ )  
		dMerge( lcp[i].second , lcp[i].second + 1 , lcp[i].first ); 
	dMerge( 0 , n , 0 ) ; 

	ll cnt = 0;
	for( int i = 0 ; i < min( sz(a[0]) , min( sz(a[1]) , sz(a[2]) ) ) ; i++ ) { 
		cnt += ans[i];
		cnt %= mod;
		cout << cnt << ' ' ;
	}
	cout << endl;
}