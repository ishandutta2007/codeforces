#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>

using namespace std;

#define all(x) x.begin(),x.end()
#define FOR(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();++it)
#define bits(x) __builtin_popcount(x)

int tabla[1024][1024];
pair<int,int> use[1024][1024];
int n;
vector<int> cus;

int calc(int first, int from) {
	int &ret=tabla[first][from];
	if (ret!=-1) return ret;
	if (from==n || from==n-1) {
		use[first][from]=make_pair(first, from<n?from:-1);
		ret=max(cus[first],(from<n?cus[from]:0));
		return ret;
	}
	ret = max(cus[from],cus[from+1]) + calc(first, from+2);
	use[first][from]=make_pair(from, from+1);
	int opt2= max(cus[first], cus[from]) + calc(from+1, from+2);
	if (opt2 < ret) {
		ret=opt2;
		use[first][from]=make_pair(first, from);
	}
	opt2= max(cus[first], cus[from+1]) + calc(from, from+2);
	if (opt2 < ret) {
		ret=opt2;
		use[first][from]=make_pair(first, from+1);
	}
	//cout<<first<<" "<<from<<": "<<ret<<endl;
	return ret;
}

int main(){
	cin>>n;
	int tmp;
	
	memset(tabla,-1,sizeof(tabla));
	for (int i=0;i<n;i++) {
		cin>>tmp;
		cus.push_back(tmp);
	}
	int time=calc(0,1);
	cout<<time<<endl;
	int fi=0, fr=1;
	for (int i=0;i<(n+1)/2;i++) {
		cout<<use[fi][fr].first+1;
		if (use[fi][fr].second!=-1) {
			cout<<" "<<use[fi][fr].second+1;
		}
		if (use[fi][fr].first==fi && use[fi][fr].second==fr) fi=fr+1;
		if (use[fi][fr].first==fi && use[fi][fr].second==fr+1) fi=fr;
		cout<<endl;
		fr+=2;
	}
	
	return 0;
}