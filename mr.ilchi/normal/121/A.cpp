/*
 * in the name of god
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
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <complex>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef complex<double> point;

ll s,e,res;
vector <ll> Q;

inline void go (int pos , ll val){
	
	if (pos!=0)
		Q.push_back (val);

	if (pos==10)
		return;

	go (pos+1, val*10 + 4);
	go (pos+1, val*10 + 7);
}

int main(){
	
	go (0,0ll);

	sort (Q.begin() , Q.end());

	cin >> s >> e;

	for (int i=0; i<(int)Q.size(); i++){
		
		ll last = s;

		if (i!=0)
			last = max (last , Q[i-1]+1);

		if (last<=Q[i]){
			
			ll end = min (e , Q[i]);

			res+= max(0ll, end - last+1) * Q[i];
		}
	}

	cout << res << endl;

	return 0;
}