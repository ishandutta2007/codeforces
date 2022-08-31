#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef  long long llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,k;
	llo mod=998244353;
	cin>>n>>k;
	pair<llo,llo> it[n];
	for(llo i=0;i<n;i++){
		cin>>it[i].a;
		it[i].a=-it[i].a;
		it[i].b=i;
	}
	sort(it,it+n);
	vector<llo> aa;
	llo ans=0;
	for(llo i=0;i<k;i++){
		aa.pb(it[i].b);
		ans-=it[i].a;
	}
	sort(aa.begin(),aa.end());
	llo tot=1;
	for(llo i=0;i<aa.size()-1;i++){
		tot=tot*(aa[i+1]-aa[i]);
		tot%=mod;
	}
	cout<<ans<<" "<<tot<<endl;
















	return 0;
}