/* In the name of Allah */
#include <bits/stdc++.h>

using namespace std;

struct Node{ 
	Node() { 
		for(int i = 0 ; i < 26 ; i++ ) 
			c[i] = NULL;
	}

	Node* c[26];
} root ; 

bool dfs( Node* node, bool w ) { 
	for(int i = 0 ; i < 26 ; i++ ) 
		if( node->c[i] != NULL ) 
			if( dfs( node->c[i] , !w ) == w ) 
				return w;
	return !w;
}

bool d( Node* node, bool w ) { 
	bool ret = !w;
	for(int i = 0 ; i < 26 ; i++ ) 
		if( node->c[i] != NULL ) { 
			bool r = d( node->c[i], !w ) ;
			if( r == !w ) 
				return r;
			else 
				ret = r;
		}
	return ret;
}


int main() { 
	int n,k;
	cin >> n >> k;

	for( int i  = 0 ; i < n ; i++ ) { 
		string s;
		cin >> s;

		Node* curr = &root;
		for(int j = 0 ; j < (int)s.size() ; j++ ) { 
			if( curr->c[s[j]-'a'] == NULL ) 
				curr->c[s[j]-'a'] = new Node();
			curr = curr->c[s[j]-'a'] ; 
		}
	}

	bool ans = dfs( &root, 1 ) ; 
	bool x = d( &root, 1 ) ;

	cerr << ans << ' ' << x << endl;
	if( ans == 0 ) 
		cout << "Second" << endl;
	else if( x == 0 ) 
		cout << "First" << endl;
	else if( k % 2 == 1 ) 
		cout << "First" << endl;
	else
		cout << "Second" << endl;

}