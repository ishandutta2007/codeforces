//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<char,char> mp; 
set<pair<int,int>> curr;

int counter =0;
bool canDo( string a , string b ) { 
	counter = 0;
	curr.clear();
	int i , j = i = 0; 
	int n = a.size();
	while( i <= n && counter <= 500*10000 ) { 
		counter++;
		char forb = '.'; 
		if( i ) forb = mp[a[i-1]]; 
		while( j < n && b[j] != forb && b[j] != a[i] ) {
			j++; 
			counter++; 
		}
		if( i && j < n && b[j] == forb && curr.count({i,j}) == 0) { 
			curr.insert( {i,j} ); 
			j++; 
			i--; 
			continue; 
		}
		if( i == n ) break;
		if( j && b[j-1] == mp[a[i]] ) 
			j--;
		i++;
	}
	return j >= n && i >= n; 
}

int main() { 
	ios::sync_with_stdio(false); cin.tie(0);
	mp['N'] = 'S'; 
	mp['S'] = 'N'; 
	mp['W'] = 'E'; 
	mp['E'] = 'W'; 

	int n; 
	cin >> n; 
	string a,b; 
	cin >> a >> b; 
	cout << (canDo(a,b) || canDo(b,a) ? "YES\n" : "NO\n" ); 
}