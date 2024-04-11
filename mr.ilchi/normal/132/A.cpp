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
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

string s;

inline int REV (int x){
	
	int ret = 0;

	for (int i=0; i<8; i++) if (x & (1<<i))
		ret+= (1<<(7-i));

	return ret;
}

int main(){
	
	getline (cin,s);

	int past = 0;

	for (int i=0; i<(int)s.size(); i++){

		if (i!=0)
			past = REV(s[i-1]);

		past-= REV(s[i]); past%=256; past = (past+256)%256;

		cout << past << endl;

		past = REV(past);

	}

	return 0;
}