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
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <complex>
#include <stack>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<double> point;
typedef long double ldb;

const ll key = 701;
const int maxN = 400 * 1000 + 10;
const int maxP = 18 + 2;

int d;
int p[maxN],dp[maxN];
ll pw[maxN];
ll val[maxN][maxP],rval[maxN][maxP];
string s;

ll get (int lo, int hi, bool REV){
	ll ret = 0 , len=0;
//	cout << "get " << lo << ' ' << hi << ' ' << REV << ' ' ;
	for (int j=19; j>=0; j--) if ((1<<j) <= (hi-lo+1)){
		ret = (REV) ? (ret = ret * pw[1<<j] + rval[hi][j]) : (ret = ret + pw[len] * val[hi][j]);	hi-=(1<<j); len+=(1<<j); 
	}
//	cout << ret << endl;
	return ret;
}

int main(){

	ios_base::sync_with_stdio(false);

	cin >> d >> s;

	if (d == 1){
		cout << "Impossible" << endl;
		return 0;
	}
	pw[0] = 1;
	for (int i=1; i<=(int)s.size(); i++)
		pw[i] = pw[i-1] * key;
	val[0][0] = rval[0][0] = s[0];
	for (int i=1; i<(int)s.size(); i++){
		val[i][0] = rval[i][0] = s[i];
		for (int j=1; (1<<j)<=i+1; j++){
			val [i][j] = val [i][j-1] + val [i-(1<<(j-1))][j-1] * pw[1<<(j-1)];	
			rval[i][j] = rval[i][j-1] * pw[1<<(j-1)] + rval[i-(1<<(j-1))][j-1];
		}
	}

	int poi = 0;
	for (int i=0; i<(int)s.size(); i++){
		poi = max(0,poi-1);
		while (get(poi,i,0) != get(poi,i,1)) poi++;
		p [i] = poi;
		dp[i] = (i) ? (max(dp[i-1],i-poi+1)) : (i-poi+1);
	}

//	for (int i=0; i<(int)s.size(); i++){
//		cout << dp[i] << endl;
//	}

	for (int len=(int)s.size()-1; len>=0; len--) if (len==0 || dp[len-1]<d){
		bool flag = false;
		for (char x = s[len]+1; x<='z'; x++){
			int poi = (len == 0) ? (0) : (max(0,p[len-1]-1)); 
			while ((poi<len) && ((get(poi,len-1,0) * key + x) != (get(poi,len-1,1) + pw[len-poi] * x))) poi++;
			if (len-poi+1 < d){
				flag = true;
				p[len] = poi;
				s[len] = val[len][0] = rval[len][0] = x;
				for (int j=1; (1<<j)<=len+1; j++){
					val [len][j] = val [len][j-1] + val [len-(1<<(j-1))][j-1] * pw[1<<(j-1)];	
					rval[len][j] = rval[len][j-1] * pw[1<<(j-1)] + rval[len-(1<<(j-1))][j-1];
				}
				break;
			}
		}
		if (!flag)
			continue;
//		cout << p[len] << endl;
		for (int i=len+1; i<(int)s.size(); i++){
			for (char x='a'; x<='z'; x++){
				int poi = max(0,p[i-1]-1);
		//		cout << " : " << poi << endl;
				while ((poi<i) && ((get(poi,i-1,0) * key + x) != (get(poi,i-1,1) + pw[i-poi] * x))) poi++;			
				if (i-poi+1 < d){
					p[i] = poi;
					s[i] = val[i][0] = rval[i][0] = x;
					for (int j=1; (1<<j)<=i+1; j++){
						val [i][j] = val [i][j-1] + val [i-(1<<(j-1))][j-1] * pw[1<<(j-1)];	
						rval[i][j] = rval[i][j-1] * pw[1<<(j-1)] + rval[i-(1<<(j-1))][j-1];
					}
					break;
				}
			}
		}
		cout << s << endl;
		return 0;
	}

	cout << "Impossible" << endl;

	return 0;
}