/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

#define sz(x) (((int) x.size()))
typedef long long ll;

vector<int> a[10] = { 
	{}  , 
	{} , 
	{ 2 } , 
	{ 3 } , 
	{ 3 , 2 , 2 } , 
	{ 5 } , 
	{ 5 , 3 } , 
	{ 7 } , 
	{ 7 , 2 , 2 , 2 } , 
	{ 7 , 3 , 3 , 2 } };
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> ans;
	for( int i = 0 ; i < n ; i++ ) 
		for( int j = 0 ; j < sz( a[s[i]-'0'] ) ; j++ ) 
			ans.push_back( a[s[i]-'0'][j] ) ; 
	sort( ans.begin(), ans.end());
	for( int i = sz(ans) - 1 ; i >= 0 ; i-- ) 
		cout << ans[i];
	cout << endl;

}