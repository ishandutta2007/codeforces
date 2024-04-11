#include<bits/stdc++.h>
using namespace std;
long long s[200000];
int n;
int q;
vector<pair<long long,int> > u;
long long ans[200000];
int main() {
	long long l,r;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",&s[i]);
	sort(s,s+n);
	for(int i=n-1;i>0;i--) s[i]=s[i]-s[i-1];
	for(int i=0;i<n-1;i++) s[i]=s[i+1];
	n--;
	sort(s,s+n);
	scanf("%d",&q);
	for(int i=0;i<q;i++) {
		scanf("%lld %lld",&l,&r);
		u.push_back(make_pair(r-l,i));
	}
	sort(u.begin(),u.end());
	int j=0;
	long long sum=0;
	for(int i=0;i<q;i++) {
		while(j<n && s[j]<=u[i].first) {
			sum+=s[j];
			j++;
		}
		ans[u[i].second]=sum+(n-j+1)*(u[i].first+1);
	}
	for(int i=0;i<q;i++) printf("%lld ",ans[i]);
	return 0;
}