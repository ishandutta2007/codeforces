//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1000 + 10; 

int a[maxN][maxN];
bitset<maxN> curr[maxN];

vector<int> X; 
int que[maxN],en;
int cnt[maxN][maxN];
int main() { 
	int n,m; scanf( "%d %d" , &n , &m ); 
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < m ; j++ ) { 
			scanf( "%d" , &a[i][j] ); 
			X.push_back(a[i][j]); 
		}
	sort(X.begin(),X.end()); 
	X.resize(unique(X.begin(),X.end()) - X.begin()); 

	int s = 0 , e = X.size(); 
	while( e - s > 1 ) { 
		int mid = (s+e)/2; 
		for( int i = 0 ; i < n ; i ++ ) { 
			for( int j = 0 ; j < m ; j++ ) 
				curr[i][j] = (a[i][j]>=X[mid]); 
		}
		bool check = false; 
		memset( cnt , 0 , sizeof cnt ); 
		for( int j = 0 ; j < m ; j++ ) { 
			en = 0;
			for( int i = 0 ; i < n && !check ; i++ ) 
				if( curr[i][j] ) { 
					for( int k = 0 ; !check && k < en ; k++ ) {
						cnt[que[k]][i]++; 
						if( cnt[que[k]][i] > 1 ) {
							check = true;
							break;
						}
					}
					que[en++] = i; 
				}
		}

		if( check ) 
			s = mid; 
		else
			e = mid; 
	}
	printf("%d\n" , X[s]); 
}