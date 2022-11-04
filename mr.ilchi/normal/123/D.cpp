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

const int MAXN = 100000+10;

int len,REP;
ll cost[MAXN][20];
string s;

bool cmp (const int &A, const int &B){
	return cost[A][REP]<cost[B][REP];
}

int getLcp (int A, int B){
	int ret = 0;
	for (int i=REP; i>=0; i--) if (max(A,B)+(1<<i)<=len && cost[A][i]==cost[B][i]){
		ret+= (1<<i); 
		A+= (1<<i);
		B+= (1<<i);
	}
	return ret;
}

int main(){
	cin >> s; 
	len=(int)s.size();
	vector <int> perm;
	for (int i=0; i<len; i++)
		perm.push_back(i);
	for (int rep=0; (1<<rep)<=2*len; rep++){
		for (int j=0; j<len; j++){
			if (rep==0)
				cost[j][rep] = s[j];
			else if (j+(1<<(rep-1))<len)
				cost[j][rep] = cost[j][rep-1] * 123456 + cost[j+(1<<(rep-1))][rep-1];
			else
				cost[j][rep] = cost[j][rep-1] * 123456;
		}
		REP = rep;
		sort(perm.begin(),perm.end(),cmp);
		int cur = 0;
		ll last=-1;
		for (int i=0; i<(int)perm.size(); i++){
			if (i==0 || cost[perm[i]][REP]!=last)
				cur++;
			last = cost[perm[i]][REP];
			cost[perm[i]][rep] = cur;
		}
	}
	ll ans = 0 , sum = 0;
	set <pii> SET;
	for (int i=len-1; i>=0; i--){
		int ind = perm[i];
		if (i!=len-1){
			int tmp = getLcp(perm[i],perm[i+1]);
			int Count=0;
			while ((!SET.empty()) && (SET.rbegin()->first)>=tmp){
				pii cur = *SET.rbegin(); SET.erase(cur);
				sum-= (ll)cur.first * cur.second;
				Count+= cur.second;
			}
			if (Count){
				sum+= (ll)Count * tmp;
				SET.insert(pii(tmp,Count));
			}
		}
		set <pii> :: iterator it = SET.upper_bound(pii(len-ind,-1));
		if ((it==SET.end()) || ((it->first)!=len-ind))
			SET.insert(pii(len-ind,1));
		else{
			pii cur = *it;
			SET.erase(it);
			SET.insert(pii(cur.first,cur.second+1));
		}
		sum+= len-ind;
		ans+= sum;
	}
	cout << ans << endl;
	return 0;
}