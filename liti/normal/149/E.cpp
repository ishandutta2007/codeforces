/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

const int maxN = 1000 + 10; 
const int maxK = 1000*100 + 10;

int nex[2][maxN], cnt[maxN];
int val[maxK];

int main() {
	string t;
	cin >> t;
	string tr = t; reverse(tr.begin(),tr.end());
	int m; cin >> m;
	int ans = 0;
	for( int q = 0 ; q < m ; q++ ) { 
		ll ret = 0;
		string s;
		cin >> s;
		string sr;
		memset(nex,0,sizeof nex);
		for( int j = 0 ; j < 2 ; j++ ) { 
			if( j == 1 ) sr = s;
			for( int i = 1 ; i < sz(s) ; i++ ) {
				int x = nex[j][i];
				while( x && s[i] != s[x] ) 
					x = nex[j][x];
				if( s[x] == s[i] ) x++;
				nex[j][i+1] = x;
			}
			reverse(s.begin(),s.end());
		}
		int curr=0;
		for( int i = 0 ; i < sz(t) ; i++ ) {
			while( curr && s[curr] != t[i] ) 
				curr = nex[0][curr];
			if( s[curr] == t[i] ) curr++;
			val[i] = curr;
			cnt[curr]++;
			if( curr == sz(s) ) curr = nex[0][curr];
		}
		curr = 0;
		for( int i = 0 ; i < sz(t) ; i++ ) {
			while( curr && sr[curr] != tr[i] ) 
				curr = nex[1][curr];
			if( sr[curr] == tr[i] ) curr++;
			int& v = val[sz(t)-i-1];
			cnt[v]--;
			v = 0;
			if( curr != 0 && curr != sz(s) ) 
				ret+= cnt[sz(s)-curr];
			if( curr == sz(s) ) curr = nex[1][curr];
		}
		if( ret > 0 ) ans++;
	}
	cout << ans << endl;
}