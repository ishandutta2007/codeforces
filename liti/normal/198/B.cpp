//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

string a[2]; 

const int maxN = 10*1000 * 100 + 100; 
int dis[maxN], que[maxN],en; 

int main() { 
	int n,k; cin >> n >> k; 
	cin >> a[0] >> a[1]; 
	memset( dis , 31 , sizeof dis ); 
	int inf = dis[0]; 
	dis[0] = 0; 

	que[en++] = 0; 
	for( int i = 0 ; i < en ; i++ ) { 
		int s = que[i]; 
		if( dis[s] > s/2 || a[s%2][s/2] == 'X'  ) { 
			dis[s] = inf; 
			continue; 
		}
		if( s/2 + 1 < n && dis[s+2] > dis[s] + 1 ) { 
			que[en++] = s + 2; 
			dis[s+2] = dis[s] + 1 ; 
		}
		if( s/2 - 1 >= 0 && dis[s-2] > dis[s] + 1 ) { 
			que[en++] = s - 2; 
			dis[s-2] = dis[s] + 1 ; 
		}
		if( ( (s ^ 1) + 2 * k ) < 2 * n  && 
			   dis[(s ^ 1) + 2 * k] > dis[s] + 1 ) { 
			dis[(s ^ 1) + 2 * k] = dis[s] + 1 ; 
			que[en++] = (s ^ 1) + 2 * k; 
		}
	}
	for( int i = n - k ; i < n ; i++ ) 
		if( min( dis[i*2] , dis[i*2+1] ) < inf ) {
			cout << "YES\n"; 
			return 0; 
		}
	cout << "NO\n"; 
}