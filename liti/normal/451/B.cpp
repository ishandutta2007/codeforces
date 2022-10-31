#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10;
int a[maxN];
vector<int> ans;

int main() { 
	int n;
	cin >> n;

	int last = 0;
	bool ch = 1;
	for(int i = 0 ; i < n ; i++ ) { 
		int num;
		cin >> num;
		a[i] = num;
		if( (ch && num < last) || (!ch && num > last ) ) {
			ans.push_back(i-1);
			ch = !ch ;
		}
		last = num;
	}

	if( ans.size() == 0 ) { 
		cout << "yes" << endl << "1 1" << endl;
		return 0;
	}
	if( ans.size() > 2 ) { 
		cout << "no" << endl;
		return 0;
	}
	if( ans.size() == 1 ) 
		ans.push_back( n - 1) ;

	reverse( a + ans[0] , a + ans[1] + 1 ) ;
	for(int i = 1 ; i < n ; i++ ) 
		if( a[i] < a[i-1] ) { 
			cout << "no" << endl;
			return 0;
		}
	cout << "yes" << endl << ans[0] + 1  << ' ' << ans[1] + 1 << endl;
}