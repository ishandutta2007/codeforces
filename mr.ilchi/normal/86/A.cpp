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
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef long double ldb;

ll l,r;

inline int cnt (ll x){

	int ret=0;

	while (x){		
		ret++;
		x/=10ll;
	}

	return ret;
}
/******************************/
inline ll pow (int x){
	
	ll ret=1;

	while (x){
		
		ret= ret*10ll;

		x--;
	}

	return ret;
}
/******************************/
int main(){

	cin >> l >> r;

	int x1= cnt (l);
	int x2= cnt (r);

	if (x1 < x2){

		ll tmp= pow (x2)/2 - 1ll;

		if (r < tmp)
			tmp= r;

		ll maxi=  tmp * (pow(x2)-tmp-1);

		if (x1 < (x2-1))
			maxi= max (maxi, (pow(x1)/2-1) * (pow(x1)/2));
		else{
			
			ll tmp= pow(x1)/2-1;

			if (tmp < l)
				tmp= l;

			maxi= max (maxi, pow(x1)-tmp-1);
		}

		cout << maxi << endl;

		return 0;
	}

	ll tmp= pow(x1)/2 - 1ll;

	if (tmp < l)
		tmp= l;

	if (tmp > r)
		tmp= r;

	cout << tmp * (pow(x1)-tmp-1) << endl;

	return 0;
}