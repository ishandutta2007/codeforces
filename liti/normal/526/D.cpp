/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;
int n,k;

const int maxN = 1000*1000 + 10;


int nex[maxN];
vector<int> c[maxN];
int st[maxN] , en[maxN];


int cnt[maxN];

void dfs( int s ) { 
	static int ind = 0;
	st[s] = ind++;
	for( auto x : c[s] ) 
		dfs( x ) ; 
	en[s] = ind;
}

int main() { 
	string s;
	cin >> n >> k;
	cin >> s; 

	int counter = 0;
	c[0].push_back( 1 );
	for( int i = 1 ; i < n ; i++ ) { 
		while( counter && s[i] != s[counter] ) 
			counter = nex[counter];
		if( s[i] == s[counter] ) 
			counter++;
	//	cout << i + 1 << ' ' << counter << endl;
		nex[i+1] = counter;
		c[counter].push_back( i + 1 ); 
	}
	dfs( 0 ); 

	for( int i = 1 ; i <= n ; i++ ) { 
		int counter = 0; 
		for( int j = 0 ; j + i <= n ; j += i ) { 
			if( !(st[i] <= st[j+i] && st[j+i] < en[i]) ) 
				break;
			counter++; 
			if( counter == k ) { 
				int s = 0 , e = i + 1; 
				while( e - s > 1 ) { 
					int m = (s+e)>>1;
					if( j + i + m <= n && st[m] <= st[j+i+m] && st[j+i+m] < en[m] ) 
						s = m;
					else
						e = m;
				}
				cnt[j+i-1]++;
				//cout << i << ' ' << s << endl;
				cnt[min( j + i + s , maxN )]--;
				break;
			}
		}
	}


	int sum = 0;
	string res = "";
	for( int i = 0 ; i < n ; i++ ) {
		sum += cnt[i];
		if( sum > 0 )
			res += '1';
		else
			res += '0';
	}
	cout << res << endl;
}