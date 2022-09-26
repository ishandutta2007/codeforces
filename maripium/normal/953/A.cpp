#include<bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 2e9;
int cur;
vector<int> po2;
vector<int> po3;

signed main() {
	int p2 = 1;
	for(p2;p2 <= INF;p2 *= 2)po2.push_back(p2);
	int p3 = 1;
	for(p3;p3 <= INF;p3 *= 3)po3.push_back(p3);
	vector<int> vals;
	for(int i = 0;i < po2.size();++i) 
		for(int j = 0;j < po3.size();++j) vals.push_back(po2[i] * po3[j]);
	sort(vals.begin(),vals.end());
	int l,r;
	cin >> l >> r;
	cout << upper_bound(vals.begin(),vals.end(),r) - lower_bound(vals.begin(),vals.end(),l);
}