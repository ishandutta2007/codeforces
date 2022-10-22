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

vector<long long> proc(vector<long long> v, long long k, long long t) {
	long long n=v.size(), libre=k, pos=0;
	vector<long long> ans;
	for (long long i=0;i<n;i++) {
		while (pos<ans.size() && ans[pos]<=v[i]){ libre++; pos++; }
		if (libre>0) {
			ans.push_back(v[i]+t);
			libre--;
		} else {
			ans.push_back(ans[pos]+t);
			pos++;
		}
	}
	return ans;
}

void prin(vector<long long> v) {
	for (int i=0;i<v.size();i++) cout<<v[i]<<" "; cout<<endl;
}

int main(){
	long long n,k1,k2,k3,t1,t2,t3,tmp;
	vector<long long> init,fin;
	cin>>k1>>k2>>k3>>t1>>t2>>t3;
	cin>>n;
	
	for (long long i=0;i<n;i++) {
		cin>>tmp;
		init.push_back(tmp);
	}
	
//	prin(init);
	fin = proc(init,k1,t1);
//	prin(fin);
	fin = proc(fin,k2,t2);
//	prin(fin);
	fin = proc(fin,k3,t3);
//	prin(fin);
	
	long long ans=0;
	for (long long i=0;i<n;i++) ans=max(ans,fin[i]-init[i]);
	
	cout<<ans<<endl;
	return 0;
}