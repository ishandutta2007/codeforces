#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		vector<pair<llo,llo>> ss;
		vector<pair<llo,llo>> tt;
		for(llo i=0;i<n;i++){
			llo x=s[i]-'0';
			if(ss.size()==0){
				ss.pb({x,1});
			}
			else{
				if(ss.back().a==x){
					ss[ss.size()-1].b+=1;
				}
				else{
					ss.pb({x,1});
				}
			}
		}
		for(llo i=0;i<n;i++){
			llo x=t[i]-'0';
			if(tt.size()==0){
				tt.pb({x,1});
			}
			else{
				if(tt.back().a==x){
					tt[tt.size()-1].b+=1;
				}
				else{
					tt.pb({x,1});
				}
			}
		}
		if(ss.size()!=tt.size() or ss[0].a!=tt[0].a){
			cout<<-1<<endl;
		}
		else{
			llo ans=0;
			llo st=-1;
			vector<llo> ee;
			for(llo i=0;i<ss.size();i++){
				ee.pb(ss[i].b-tt[i].b);
			}
		
			for(llo i=1;i<ss.size();i+=2){
				ee[i]*=-1;
			}
			for(llo i=0;i+1<ee.size();i++){
				ans+=abs(ee[i]);
				ee[i+1]-=ee[i];
			}
			cout<<ans<<endl;


		}
	}




	return 0;
}