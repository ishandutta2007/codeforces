//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

const int maxN = 100 + 10; 

string a[maxN]; 

void die() { 
	cout << "YES" << endl;
	exit(0); 
}

int main() { 
	string s; 
	cin >> s;

	int n; cin >> n;
	for(int i = 0; i < n; i++){ 
		cin >> a[i]; 
		if( a[i] == s ) die(); 
		for(int j = 0; j <= i; j++) { 
			string x = a[i] + a[j]; 
			string y = a[j] + a[i];
			if( x.substr(1,2) == s || y.substr(1,2) == s )
				die();
		}
	}

	cout << "NO" << endl;
}