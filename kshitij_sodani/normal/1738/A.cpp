#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
llo aa[100001];
llo bb[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo su=0;
		llo ans=0;
		for(llo i=0;i<n;i++){
			cin>>aa[i];
			su+=aa[i];
		}
		vector<llo> tt;
		vector<llo> ss;
		for(llo i=0;i<n;i++){
			cin>>bb[i];
			ans+=bb[i];
			if(aa[i]==0){
				ss.pb(bb[i]);
			}
			else{
				tt.pb(bb[i]);
			}
		}
		sort(ss.begin(),ss.end());
		sort(tt.begin(),tt.end());
		if(ss.size()<tt.size()){
			swap(ss,tt);
		}
		if(ss.size()==tt.size()){
			pair<llo,llo> mi={1e9+1,-1};
			for(llo i=0;i<n;i++){
				mi=min(mi,{bb[i],i});
			}
			ans=2*ans-mi.a;
		}
		else{
			reverse(ss.begin(),ss.end());
		
			for(llo i=0;i<tt.size();i++){
				ans+=ss[i];
				ans+=tt[i];
			}
		}
		cout<<ans<<endl;

	}
	



	return 0;
}