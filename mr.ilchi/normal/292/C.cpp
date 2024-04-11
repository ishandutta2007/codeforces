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
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <bitset>
#include <iomanip>
#include <utility>

using namespace std;

typedef long long LL;
typedef complex<double> point;
typedef long double ldb;
typedef pair<int,int> pii;

int n;
int a[1000],cnt[1000],t[1000],test[1000];
vector < pair < pii , pii > > Q;

inline void BT (int rem, int pos, int len){
	if (rem * 3 < (len-pos)) return;
	if (rem > (len-pos)) return;
	if (pos==len){
		if (rem==0){
			Q.push_back(make_pair(pii(test[0], test[1]), pii(test[2], test[3])));
			return;
		}
		return;
	}
	if (rem==0)
		return;
	if (t[pos]==0){
		test[4-rem] = 0;
		BT(rem-1, pos+1, len);
		return;
	}
	int cur = 0;
	for (int i=pos; i<min(len,pos+3); i++){
		cur = cur * 10 + t[i];
		if (cur>255)
			return;
		test[4-rem] = cur;
		BT(rem-1, i+1, len);
	}
}

inline void go (int pos, int len, int c){
	if (pos == (len+1)/2){
		if (c!=n)
			return;
		for (int i=pos; i<len; i++)
			t[i] = t[len-i-1];
		BT(4, 0, len);
		return;
	}
	for (int i=0; i<n; i++){
		cnt[a[i]]++;
		t[pos] = a[i];
		go(pos+1, len, c + (cnt[a[i]]==1));
		cnt[a[i]]--;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=4; i<=12; i++)
		go(0, i, 0);
	cout << Q.size() << endl;
	for (int i=0; i<(int)Q.size(); i++){
		cout << Q[i].first.first  << '.';
		cout << Q[i].first.second << '.';
		cout << Q[i].second.first << '.';
		cout << Q[i].second.second << endl;
	}
	return 0;
}