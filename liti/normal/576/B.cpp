//In the name of Allah    
#include <bits/stdc++.h>    
using namespace std;    

#define __sz(x) ((int)(x).size())    
typedef long long ll;    

const int maxN = 1000*100 + 100; 
int a[maxN];
int mark[maxN];

int main() { 
	int n; 
	cin >> n; 
	for( int i = 0 ; i < n ; i++ ) { 
		cin >> a[i]; 
		a[i]--; 
	}
	for( int i = 0 ; i < n ; i++ ) 
		if( a[i] == i ) { 
			cout << "YES" << endl;
			for( int j = 0 ; j < n ; j++ ) 
				if( j != i ) 
					cout << i + 1 << ' ' << j + 1 << '\n' ; 
			return 0;
		}
	for( int i = 0 ; i < n ; i++ ) { 
		int cnt = 0;
		int t = i;
		while( !mark[t] ) { 
			cnt++; 
			mark[t] = true;
			t = a[t];
		}
		if( cnt % 2 == 1 ) { 
			cout << "NO" << endl;
			return 0;
		}
	}

	memset( mark , 0 , sizeof mark ) ; 
	for( int i = 0 ; i < n ; i++ ) 
		if( a[a[i]] == i ) { 
			cout << "YES" << endl;
			cout << i + 1 << ' ' << a[i] + 1 << '\n';
			mark[i] = mark[a[i]] = 1;
			for( int j = 0 ; j < n ; j++ ) { 
				int t = j;
				while( !mark[t] ) { 
				   mark[t] = true;	
				   cout << i + 1 << ' ' << t + 1 << '\n';
				   t = a[t];
				   i = a[i];
				}
			}
			return 0;
		}
	cout << "NO" << endl;
}