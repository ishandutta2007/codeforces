//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

int cnt[16];

void die() { 
	cout << "YES" << endl;
	exit(0);
}

int main() { 
	int n, k;
	cin >> n >> k;
	int s = (1<<k);
	for( int i = 0; i < n ;i++ ) { 
		int mask = 0;
		for(int j = 0 ; j < k ; j++ )  { 
			int x; cin >> x;
			mask = mask * 2 + x; 
		}
		if( !mask ) die();
		cnt[mask]++; 
	}
	for( int i = 0 ; i < s ; i++ ) 
		for( int j = 0 ; j < s ; j++ ) 
			if( cnt[i] && cnt[j] && (i & j) == 0) die();
	cout << "NO" << endl;
}