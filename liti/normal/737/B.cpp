//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld; 
typedef pair<int,int> pii; 

int main() { 
	int n,a,b,k; cin >> n >> a >> b >> k; 
	string s; cin >> s; 
	int sum = 0; 
	for( int j,i=0; i < n ; i = j ) { 
		if( s[i] == '1' ) 
			j = i + 1 ; 
		else { 
			for( j = i ; j < n && s[j] == '0' ; j++ ); 
			sum += (j-i) / b; 
		}
	}
	cout << sum - a+1 << endl;
	int cnt = sum - a+1; 
	for( int j,i=0; i < n ; i = j ) { 
		if( s[i] == '1' ) 
			j = i + 1 ; 
		else { 
			for( j = i ; j < n && s[j] == '0' ; j++ ) 
				if( cnt && (j-i) % b == b - 1 ) { 
					cout << j+1 <<  " " ; 
					cnt--; 
				}
		}
	}
	cout << endl;
}