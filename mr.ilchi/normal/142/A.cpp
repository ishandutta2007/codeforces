/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;

int n;
ll MIN = (1ll<<60);
ll MAX = -1;

inline void check (ll A, ll B, ll C){
	MIN = min (MIN , (A+1) * (B+2) * (C+2) - A*B*C);
	MAX = max (MAX , (A+1) * (B+2) * (C+2) - A*B*C);
}

int main(){
	
	cin >> n;

	vector <int> p;

	for (int j=1; j*j<=n; j++) if (n%j==0){
		p.push_back (j);
		p.push_back (n/j);
	}	

	for (int i=1; i<=1000; i++) if (n%i==0){
		int ttmp = n/i;
	//	cout << tmp << endl;
		for (int jj=0; jj<(int)p.size(); jj++) if (ttmp%p[jj]==0){
			int j = p[jj];
			int tmp = ttmp/j;
		//	cout << tmp << ' ' << i << ' ' << j << ' ' << n << endl;
			check (i,j,tmp);
			check (i,tmp,j);
			check (j,i,tmp);
			check (j,tmp,i);
			check (tmp,i,j);
			check (tmp,j,i);
		}
	}

	cout << MIN << ' ' << MAX << endl;

	return 0;
}