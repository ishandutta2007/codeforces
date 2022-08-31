#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n,k;
llo it[101][101];
vector<pair<llo,llo>> ss[101][101];
vector<llo> tt;
llo vis[101];
llo ans2=1e18;
void brute(llo ind){
	if(ind==(k/2)-1){
		llo ans=0;
		/*if(ans2==0){
			return;
		}*/
		/*for(llo i=0;i<tt.size();i++){
			llo j=i+1;
			if(j==tt.size()){
				j=0;
			}
			int co=0;
			for(auto p:ss[tt[i]][tt[j]]){
				if(vis[p.b]==0){
					ans+=p.a;
					break;
				}
				else{
					co++;
				}
			}
			if(co==ss[tt[i]][tt[j]].size()){
				return;
			}
		}*/
		for(llo i=0;i<tt.size();i++){
			llo j=i+1;
			if(j==tt.size()){
				j=0;
			}
			int co=0;
			//cout<<tt[i]<<",,"<<tt[j]<<endl;
			for(auto p:ss[tt[i]][tt[j]]){
				if(vis[p.b]==0){
					ans+=p.a;
					co=1;
					//cout<<i<<",,"<<p.b<<endl;
					break;
				}
			}
			if(co==0){
				return;
			}
		}
		/*if(ans==0){
			for(auto j:tt){
				cout<<j<<",";
			}
			cout<<endl;
			for(llo i=0;i<tt.size();i++){
				llo j=i+1;
				if(j==tt.size()){
					j=0;
				}
				int co=0;
				cout<<tt[i]<<",,"<<tt[j]<<endl;
				for(auto p:ss[tt[i]][tt[j]]){
					if(vis[p.b]==0){
						ans+=p.a;
						//cout<<i<<",,"<<p.b<<endl;
					
					}
					else{
						co++;
					}
				}
				if(co==ss[tt[i]][tt[j]].size()){
					return;
				}
			}
		}*/
		ans2=min(ans2,ans);

	}
	else{
		for(llo i=0;i<n;i++){
			tt.pb(i);
			vis[i]+=1;
			brute(ind+1);
			vis[i]-=1;
			tt.pop_back();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			cin>>it[i][j];
		}
	}
	if(k==2){
		llo ans=1e18;
		for(llo i=1;i<n;i++){
			ans=min(ans,it[0][i]+it[i][0]);
		}
		cout<<ans<<endl;
		return 0;
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			for(llo kk=0;kk<n;kk++){
				if(kk==i or kk==j){
				}
				else{
					ss[i][j].pb({it[i][kk]+it[kk][j],kk});
				}
			}
			sort(ss[i][j].begin(),ss[i][j].end());
			while(ss[i][j].size()>4){
				ss[i][j].pop_back();
			}
		}
	}
	tt.pb(0);
	vis[0]+=1;
	brute(0);
	cout<<ans2<<endl;

 
 
	return 0;
}