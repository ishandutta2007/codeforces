#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <set>
#include <algorithm>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
vector<llint> pvec, nvec;
vector<llint> pans, nans;

void calc(vector<llint> &vec, vector<llint> &ans, llint s, llint t)
{
	if(vec.size() == 0) return;
	vector<P> tmp;
	llint res;
	for(int i = 0; i < vec.size(); i++){
		llint v = vec[i];
		cout << 1 << " " << s << " " << t << " " << v << endl;
		cin >> res;
		tmp.push_back(P(res, v));
	}
	sort(tmp.begin(), tmp.end());
	
	llint u = tmp.back().second;
	vector<llint> lvec, rvec;
	for(int i = 0; i < tmp.size(); i++){
		llint v = tmp[i].second;
		if(v == u) continue;
		cout << 2 << " " << s << " " << u << " " << v << endl;
		cin >> res;
		if(res > 0) lvec.push_back(v);
		else rvec.push_back(v);
	}
	reverse(lvec.begin(), lvec.end());
	
	for(int i = 0; i < rvec.size(); i++) ans.push_back(rvec[i]);
	ans.push_back(u);
	for(int i = 0; i < lvec.size(); i++) ans.push_back(lvec[i]);
	
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	int res;
	for(int i = 3; i <= n; i++){
		cout << 2 << " " << 1 << " " << 2 << " " << i << endl;
		cin >> res;
		if(res > 0) pvec.push_back(i);
		else nvec.push_back(i);
	}
	
	calc(pvec, pans, 1, 2);
	calc(nvec, nans, 2, 1);
	//reverse(pans.begin(), pans.end());
	
	cout << 0 << " " << 1 << " ";
	for(int i = 0; i < nans.size(); i++) cout << nans[i] << " ";
	cout << 2 << " ";
	for(int i = 0; i < pans.size(); i++) cout << pans[i] << " ";
	cout << endl;
	
	return 0;
}