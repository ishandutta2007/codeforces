#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

map<pair<int, vector<int> >, int> mem;

int get(int s, vector<int> rmu) {
	if (s==0) return 0;
	sort(rmu.begin(), rmu.end());
	if (mem.count({s, rmu})) return mem[{s, rmu}];
	set<int> can;
	int i2=0;
	for (int x=1;x<=s;x++){
		while (i2<(int)rmu.size()&&rmu[i2]<x) i2++;
		if (i2<(int)rmu.size()&&rmu[i2]==x) continue;
		vector<int> ne=rmu;
		ne.push_back(x);
		int t=get(s-x, ne);
		can.insert(t);
	}
	for (int i=0;;i++){
		if (can.count(i)==0){
			mem[{s, rmu}]=i;
			return i;
		}
	}
	assert(0);
}

int v[111];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=0;
	for (int i=0;i<=10;i++){
		for (int j=0;j<i+1;j++){
			v[t]=i;
			t++;
		}
	}
	int n;
	cin>>n;
	int x=0;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		x^=v[a];
	}
	if (x==0){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
}