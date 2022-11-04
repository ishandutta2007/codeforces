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

const int maxN = 100 * 1000 + 10;

int n,k;
int t[maxN];
vector <pii> st,pn;
vector <pii> group[maxN];

int main(){

	cin >> n >> k;

	for (int i=1; i<=n; i++){
		int cost,type; cin >> cost >> type;
		if (type==1) st.push_back(pii(cost,i));
		if (type==2) pn.push_back(pii(cost,i));
		t[i] = type;
	}

	sort(pn.begin(),pn.end());
	sort(st.begin(),st.end());

	int now=1;

	for (int i=(int)st.size()-1; i>=0; i--){
		group[now].push_back (st[i]);
		now = min(k,now+1);
	}

	for (int i=0; i<(int)pn.size(); i++){
		group[now].push_back (pn[i]);
		now = min(k,now+1);
	}

	double sum = 0;

	for (int i=1; i<=k; i++){
		bool flag = false;
		if (t[group[i][0].second] == 1)
			flag = true;
		int mini = group[i][0].first;
		for (int j=0; j<(int)group[i].size(); j++){
			mini = min (mini,group[i][j].first);
			sum+= group[i][j].first;
		}
		if (flag)
			sum-= mini/2.0;
	}

	cout << fixed << setprecision(1) << sum << endl;

	for (int i=1; i<=k; i++){
		cout << group[i].size() << ' ';
		for (int j=0; j<(int)group[i].size(); j++)
			cout << group[i][j].second << ' ';
		cout << endl;
	}

	return 0;
}