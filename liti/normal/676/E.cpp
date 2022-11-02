//In the name of Allah
#include <bits/stdc++.h>
using namespace std;

typedef long long ll; 
typedef pair<int,int> pii; 

const int maxN = 100 * 1000 + 10; 
bool isset[maxN]; 
int a[maxN]; 

int main() { 
	ios::sync_with_stdio(false); cin.tie(0); 
	int n,k; cin >> n >> k; 
	n++; 
	string dummy; getline(cin,dummy);
	int t = 0; 
	for( int i =0 ; i < n ; i++ ) { 
		getline(cin,dummy); 
		if( dummy == "?" ) continue; 
		a[i] = atoi( dummy.c_str() ) ; 
		isset[i] = true; 
		t++; 
	}
	if( k == 0 ) { 
		cout << (((isset[0]&&a[0]==0)||(!isset[0]&&t%2==1))?"Yes":"No") << endl;
		return 0;
	}

	bool L = false; 
	int kk = abs(k); 
	if( n % 2 == 0 && t != n ) L = true; 
	else if( t == n ) { 
		for( int i = 0 ; i < n ; i++ )  { 
			if( abs(a[i])%kk != 0 ) { 
				a[n] = 1;
				break;
			}
			a[i+1] += a[i]/k; 
		}
		L |= (a[n]==0); 
	} 
	cout << (!L?"No":"Yes") << endl;
}