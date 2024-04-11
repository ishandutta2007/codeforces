#include <bits/stdc++.h>

using namespace std;

const int maxN = 1000*100 + 10;

bool used[maxN];
bool isNotPrime[maxN];

vector<int> ans;
int main() { 
	int n;
	cin >> n;

	for(int i = 2 ; i < n ; i++ ) 
		if( !isNotPrime[i] ) 
			for(int j = i + i ; j <= n ; j+=i ) 
				isNotPrime[j] = true;
	for(int i = n ; i > 1 ; i-- ) { 
		if( isNotPrime[i] ) 
			continue;
		int counter = 0 ; 
		int last = -1;
		int chance = -1;
		for(int j = i ;  j <= n ; j += i ) {
			if( !used[j] ) { 

				int tmp = j; 
				while( tmp % i == 0 ) 
					tmp/=i;
				if( last == -1 && tmp != 1 && tmp < i ) 
					last = j;
				chance = j;
				counter++;
				if( last != j ) {
					ans.push_back( j ) ; 
					used[j] = true;
				}
			}
		}
		if( counter % 2 ) {
			if( last == -1 ) { 
				ans.pop_back();
				used[chance] = false;
			}
		} else if ( last != -1 )  {
			ans.push_back( last ) ;
			used[last] = true;
		}
	}

	cout << ans.size() / 2 << endl;
	for(int i =0 ; i < ans.size() ; i+= 2 ) 
		cout << ans[i] << ' ' << ans[i+1] << endl;
}