// In the name of Allah
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 100*100*10 + 10;

int sz[maxN];
string s;

struct cmp { 
	bool operator() (const int& a , const int& b)  { 
		int s_s = min( sz[a], sz[b] ) ;
		return s[a+s_s-1] < s[b+s_s-1] ;
	}
};

multiset<int, cmp> curr;

int main() { 
	int k;
	cin >> s >> k;

	int n = s.size();
	if( k > 1LL*n*(n+1)/2 ) {
		cout << "No such line." << endl;
		return 0;
	}

	for( int i = 0 ; i < n ; i++ ) {
		sz[i] = 1;
		curr.insert(i);
	}

	for( int i = 1 ; i < k ; i++ ) {
		int x = *curr.begin();
		curr.erase(curr.begin());
		sz[x]++;
		if( x + sz[x] > n ) 
			continue;
		curr.insert(x);
	}

	int x = *curr.begin();
	cout << s.substr( x, sz[x] ) << endl;
}