#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000 + 10;
const int maxK = 10000*100 + 10;
long long a[2*maxN];
long long a1[maxK], a2[maxK];
set<pair<long long,int> > s;

int main() { 
	int n,m,k,p;
	cin >> n >> m >> k >> p;

	for(int i = 0 ; i < n ; i++ ) 
		for(int j = 0 ; j < m ; j++ ) { 
			int num;
			cin >> num;
			a[i] += num;
			a[n+j] += num;
		}

	for(int i =  0 ; i < n ; i++ )
		s.insert( make_pair( a[i], i ) ) ;

	long long ans =0 ; 
	for(int i =0 ; i < k ; i++ ) { 
		ans += (*s.rbegin()).first; 
		a1[i+1] = ans;
		pair<long long,int> x = *s.rbegin();
		s.insert( make_pair( x.first - p*m , x.second ) ) ; 
		s.erase( x ) ; 
	}

	s.clear();
	long long tmp = 0 ; 
	for(int i =0 ; i < m ; i++ ) 
		s.insert( make_pair( a[i+n] , i + n ) ) ; 
	for(int i =0 ; i < k ; i++ ) { 
		tmp += (*s.rbegin()).first; 
		a2[i+1] = tmp; 
		pair<long long,int> x = *s.rbegin();
		s.insert( make_pair( x.first - p*n , x.second ) ) ; 
		s.erase( x ) ; 
	}

	ans = -1000000000LL * 1000000000 ; 
	for(long long i = 0 ; i <= k ; i++ ) 
	{
		ans = max( ans, a1[i] + a2[k-i] - p*i*(k-i) ) ; 
	}

	cout << ans << endl;
}