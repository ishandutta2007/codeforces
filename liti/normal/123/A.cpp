/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*10 + 100;
pair<int,char> a[26];
char ans[maxN];

bool isPrime( int num ) { 
	for( int i = 2 ; i < num ; i++ ) 
		if( num % i == 0 ) 
			return false;
	return true;
}

int main() { 
	string s;
	cin >> s;
	for( int i = 0 ; i < 26; i++ ) 
		a[i].second = i + 'a';
	for( int i =0  ; i < s.size() ; i++ ) 
		a[s[i]-'a'].first++;

	int mInd = max_element( a , a + 26 ) - a;
	char ch = mInd + 'a';
	
	for( int j = 2 ; j <= s.size() ; j+= 2 ) 
			if( ans[j] != ch ) { 
				ans[j] = ch;
				a[mInd].first--;
			}

	for( int i = 3 ; i <= s.size() ; i++ ) { 
		if( !isPrime(i) )
			continue;
		if( i*2 > s.size() ) 
			continue;
		for( int j = i ; j <= s.size() ; j+= i ) 
			if( ans[j] != ch ) { 
				ans[j] = ch;
				a[mInd].first--;
			}
	}

	if( a[mInd].first < 0 ) { 
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	sort( a, a + 26 ) ;
	for( int j = 1 ; j <= s.size() ; j++ ) 
		if( ans[j] == ch ) 
			cout << ans[j] ;
		else { 
			int ind = lower_bound( a , a + 26 , make_pair( 1 , 'a' )  ) - a; 
			a[ind].first--;
			cout << a[ind].second ;
		}
	cout << endl;

}