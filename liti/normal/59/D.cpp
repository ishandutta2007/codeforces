/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10; 
const int maxS = 3*maxN;


int a[maxS];
int p[maxS];
int b[maxN][3];

inline void smin( int& a , int& b ) { 
	a =  p[a] > p[b] ? swap(a,b),a : a;
}


int main() { 
	int n;
	cin >> n;

	for( int i = 0 ; i < 3*n ; i++ ) {
		cin >> a[i];
		p[a[i]] = i;
	}

	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < 3 ; j++ )
			cin >> b[i][j];


	int k;
	cin >> k;

	for( int i = 0 ; i < n ; i++ ) { 
		smin( b[i][0] , b[i][1] ) ; 
		smin( b[i][0] , b[i][2] ) ; 
		if( k == b[i][1] || k == b[i][2] ) { 
			for( int j = 1 ; j <= 3*n ; j++ ) 
				if( j != k ) 
					cout << j << ' ';
			cout << endl;
			break;
		}
		if( k != b[i][0] ) 
			continue;

		vector<int> curr;
		for( int j = 0 ; j <= i ; j++ ) 
			for( int x = 0 ; x < 3 ; x++ ) 
				if( !( j == i && x == 0 ) ) 
					curr.push_back( b[j][x] ) ; 
		sort( curr.begin() , curr.end() ) ; 

		for( int j = i + 1 ; j < n ; j++ ) 
			for( int x = 0 ; x < 3 ; x++ ) 
				curr.push_back( b[j][x] ) ; 

		int ind = max( find( curr.begin() , curr.end() , b[i][1] ) , find( curr.begin() , curr.end() , b[i][2] ) ) - 
			curr.begin() ; 

		sort( curr.begin() + ind + 1 , curr.end() ) ; 

		copy( curr.begin() , curr.end() , ostream_iterator<int>( cout , " " ) ) ;
		cout << endl;
		break;
	}
}