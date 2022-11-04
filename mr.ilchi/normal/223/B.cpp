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

const int MAXN = 200000+10;

int pre[MAXN],nex[MAXN];
string s,t;
vector <int> store[100];

int main(){
	cin >> s >> t;
	int ns = (int)s.size();
	int nt = (int)t.size();
	int poi = 0;
	for (int i=0; i<ns; i++){
		if (poi<nt && s[i]==t[poi])
			poi++;
		pre[i]=poi-1;
	}
	poi=nt-1;
	for (int i=ns-1; i>=0; i--){
		if (poi>=0 && s[i]==t[poi])
			poi--;
		nex[i] = poi+1;
	}
	for (int i=0; i<nt; i++)
		store[t[i]-'a'].push_back(i);
	bool bad = false;
	for (int i=0; i<ns; i++){
		int ind = s[i]-'a';
		if (store[ind].empty()){
			bad = true;
			break;
		}
		int lef = (i==0) ? (-1) : (pre[i-1]);
		int rig = (i==ns-1) ? (nt) : (nex[i+1]);
		lef++; rig--;
		if (store[ind].back()<rig || lef<rig){
			bad = true;
			break;
		}
		if (*lower_bound(store[ind].begin(),store[ind].end(),rig) > lef){
			bad = true;
			break;
		}
	}
	if (bad)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}