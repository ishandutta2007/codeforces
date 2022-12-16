#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const int N=1001001;
P a[N],b[N];
set<P> s1,s2;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	P mn{1e10,1e10};
	P mnb{1e10,1e10};
	for(int i=0;i<n;i++){
		cin>>a[i].first>>a[i].second;
		mn=min(mn,a[i]);
		b[i]=P{-a[i].first,-a[i].second};
		mnb=min(mnb,b[i]);
	}
	for(int i=0;i<n;i++){
		s1.insert(P{a[i].first-mn.first,a[i].second-mn.second});
		s2.insert(P{b[i].first-mnb.first,b[i].second-mnb.second});
	}
	puts(s1==s2?"YES":"No");
	return 0;
}