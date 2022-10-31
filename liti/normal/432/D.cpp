/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

const int maxN = 100*100*10 + 10;
int f[maxN];
vector<int> c[maxN];
vector<pair<int,int>> ans;
int last;
pair<int,bool> dfs( int s ) { 
	pair<int,bool> ret = {0,false};
	if( s == last ) 
		ret = {0,true};
	ret.first++;

	for( auto x : c[s] ) { 
		auto a = dfs(x) ; 
		ret.second |= a.second;
		ret.first += a.first;
	}

//	cout << s << ' ' << ret.first << ' '  << ret.second << endl;
	if( ret.first > 0 && ret.second ) 
		ans.push_back( {s + 1, ret.first} ) ; 
	return ret;
}

int main() { 
	string s;
	cin >> s;

	int ind = 0 ; 
	for( int i = 1 ; i < (int)s.size() ; i++ ) { 
		while( ind != 0 && s[ind] != s[i] ) 
			ind = f[ind-1];
		if( s[ind] == s[i] ) 
			ind++;
		f[i] = ind;
		if( ind != 0 )
			c[ind-1].push_back(i);
	}
	 

	last = s.size() - 1;

	for( int i = 0 ; i < s.size() ; i++ ) 
		if( f[i] == 0 ) 
			dfs(i) ; 

	cout << ans.size() << endl;
	sort( ans.begin() ,ans.end() ) ;

	for( int i = 0 ; i < ans.size() ; i++ ) 
		cout << ans[i].first << ' ' << ans[i].second << endl;
}