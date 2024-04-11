#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,k,x;
	cin>>n>>k>>x;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}

	sort(it,it+n);
	vector<llo> ss;
	llo ans=n;
	for(int i=0;i<n;i++){
	//	cout<<it[i]<<":";
	}
	//cout<<endl;

	for(llo i=1;i<n;i++){
		ss.pb(((max(it[i]-it[i-1]-1,(llo)0)))/x);
		//cout<<ss.back()<<":";
	}
	//cout<<endl;
	sort(ss.begin(),ss.end());
	for(auto j:ss){
		if(j<=k){
			k-=j;
			ans--;
		}
	}
	cout<<ans<<endl;










	return 0;
}