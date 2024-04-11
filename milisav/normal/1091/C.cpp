#include<bits/stdc++.h>
using namespace std;
vector<long long> f;
long long m;
long long fun(long long u) {
	long long v=m/u;
	return v+(v*(v-1)/2)*u;
}
int main()
{
	int n;
	scanf("%d",&n);
	m=n;
	for(int i=1;i*i<=n;i++) {
		if(n%i==0) {
			f.push_back(fun(i));
			f.push_back(fun(n/i));
		}
	}
	sort(f.begin(),f.end());
	for(int i=0;i<f.size();i++) {
		if(i==0 || f[i]!=f[i-1]) printf("%lld ",f[i]);
	}
	return 0;
}