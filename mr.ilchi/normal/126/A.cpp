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
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

ll t1,t2,x1,x2,t0;

int main(){

	cin >> t1 >> t2 >> x1 >> x2 >> t0;

	if (t1==t2){
		cout << x1 << ' ' << x2 << endl;
		return 0;
	}

	if (t0==t1){
		cout << x1 << ' ' << 0 << endl;
		return 0;
	}

	if (t0==t2){
		cout << 0 << ' ' << x2 << endl;
		return 0;
	}

	ll a=0 , b=x2;

	for (int i=1; i<=x1; i++){
		
	//	t0 * i + t0 * p <= t1 * i + t2 * p;
	//
	//	i * (t0-t1) <= p * (t2-t0);

		ll now = (i*(t0-t1)+(t2-t0-1))/(t2-t0);

		if (now>x2)
			continue;

		ll s1 = a*t1 + b*t2;
		ll m1 = a+b;

		ll s2 = i*t1 + now*t2;
		ll m2 = i+now;

		if (s2 * m1 < s1 * m2){
			a = i , b = now;
		}

		else if (s2*m1 == s1*m2 && i+now>a+b){
			a = i;
			b = now;
		}
	}

	cout << a << ' ' << b << endl;
	
	return 0;
}