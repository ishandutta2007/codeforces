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

const int maxN = 150 + 5;
const int base = 100 + 3;

const int d[] = {-1,1};

int k;
int dp[2*maxN][maxN][maxN][2];
string s;

inline int go (int place , int change , int pos , int dir){

	if (pos==(int)s.size()){
		if (change%2)
			return 0;
		return max(place,-place);
	}

	int &ret = dp[place+base][change][pos][dir];

	if (ret!=-1)
		return ret;

	if (s[pos]=='T'){
		ret = max (ret , go(place,change,pos+1,1-dir));
		if (change)
			ret = max (ret , go(place+d[dir],change-1,pos+1,dir));
	}
	else{
		ret = max (ret , go(place+d[dir],change,pos+1,dir));
		if (change)
			ret = max (ret , go(place,change-1,pos+1,1-dir));
	}

	return ret;
}

int main(){
	
	cin >> s >> k;

	memset (dp , -1, sizeof dp);

	cout << go(0,k,0,0) << endl;

	return 0;
}