//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;
typedef pair<int,int> pii;

int mark[60 * 2];

int main() { 
	int h, m, s, t1, t2; 
	cin >> h >> m >> s >> t1 >> t2; 
	t1 = t1 * 10 % 120; 
	t2 = t2 * 10 % 120; 
	h = h * 10 % 120;
	s *= 2;
	m *= 2;

	mark[s] = -1; 

	if( s == 0 ) 
		mark[m] = -1;
	else
		mark[m+1] = -1;

	if( m == 0 && s == 0 ) 
		mark[h] = -1;
	else
		mark[h+1] = -1;



	for( int i = t1 ; mark[i] == 0 ; i = (i+1) % 120 ) mark[i] = 1; 
	mark[t1] = 0;
	for( int i = t1 ; mark[i] == 0 ; i = (i+119) % 120 ) mark[i] = 1; 


	cout << (mark[t2] == 1 ? "YES" : "NO") << endl;
}