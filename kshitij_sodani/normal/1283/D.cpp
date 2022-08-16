//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	sort(it,it+n);
	priority_queue<pair<llo,pair<llo,llo>>> ss;

	for(llo i=0;i<n;i++){
		if(i+1<n){
			if(it[i+1]>it[i]+1){
				llo mid=(it[i]+it[i+1])/2;
				ss.push({-1,{it[i]+1,mid}});
				if(mid+1<it[i+1]){
					ss.push({-1,{it[i+1]-1,mid+1}});
				}
			}
		}
		if(i==0){
			ss.push({-1,{it[0]-1,-2e9}});
		}
		if(i==n-1){
			ss.push({-1,{it[n-1]+1,2e9}});
		}
	}
	llo ans=0;
	vector<llo> ans2;
	for(llo i=0;i<m;i++){
		pair<llo,pair<llo,llo>> no=ss.top();
		ss.pop();
		ans2.pb(no.b.a);
		ans+=abs(no.a);
		if(no.b.a<no.b.b){
			ss.push({no.a-1,{no.b.a+1,no.b.b}});
		}
		else if(no.b.a>no.b.b){
			ss.push({no.a-1,{no.b.a-1,no.b.b}});
		}
	}
	cout<<ans<<endl;
	for(auto j:ans2){
		cout<<j<<" ";
	}
	cout<<endl;



 
	return 0;
}