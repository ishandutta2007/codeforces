#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back

int query(vector<int> zz){
	cout<<"? ";
	cout<<zz.size()<<" ";
	for(auto j:zz){
		cout<<j<<" ";
	}
	cout<<endl;
	string s;
	cin>>s;
	if(s=="YES"){
		return 1;
	}
	return 0;
}

vector<int> pre[20];
vector<int> pre2[20];
int ans[20];
vector<pair<int,int>> adj[20];
int vis[20];
vector<int> tt;
void dfs(int no){
	vis[no]=1;
	tt.pb(no);
	if(ans[no]==-1){
		ans[no]=0;
	}
	for(auto j:adj[no]){
		if(vis[j.a]==0){
			ans[j.a]=(ans[no]^j.b);
			dfs(j.a);
		}
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	if(n==1){
		cout<<"! "<<1<<endl;
		string ss;
		cin>>ss;
		return 0;
	}
	vector<pair<int,int>> xx;
	for(int i=0;i<17;i++){
		if((1<<i)>n){
			continue;
		}
		vector<int> aa;
		vector<int> bb;
		for(int j=1;j<=n;j++){
			if((j&(1<<i))){
				bb.pb(j);
			}
			else{
				aa.pb(j);
			}
		}
		pre[i]=aa;
		pre2[i]=bb;
	}
	for(int i=0;i<17;i++){
		ans[i]=-1;
	}
	int ind=0;
	for(int i=0;i<17;i++){
		if(pre[i+1].size() and pre2[i+1].size()){
			vector<int> yy;
			yy.pb(query(pre2[ind]));
			yy.pb(query(pre2[ind]));
			yy.pb(query(pre2[i+1]));
			yy.pb(query(pre2[i+1]));
			yy.pb(query(pre2[ind]));
			if(yy[0]==yy[1]){
				ans[ind]=yy[0];
				ind=i+1;
			}
			else if(yy[2]==yy[3]){
				ans[i+1]=yy[2];
			}
			else{
				if(yy[1]==yy[4]){
					ans[ind]=yy[1];
					ind=i+1;
				}
				else{
					adj[ind].pb({i+1,yy[1]^yy[3]});
					adj[i+1].pb({ind,yy[1]^yy[3]});
				}
			}
		}
	}
	int su=0;
	for(int i=0;i<20;i++){
		if(ans[i]>=0){
			if(vis[i]==0){
				tt.clear();
				dfs(i);
				for(auto j:tt){
					su+=ans[j]*(1<<j);
				}
			}
		}
		
		
	}
	for(int i=0;i<20;i++){
		if(vis[i]==0){
			tt.clear();
			dfs(i);
			int su2=0;
			int su3=0;
			for(auto j:tt){
				su2+=ans[j]*(1<<j);
				su3+=(1-ans[j])*(1<<j);
			}
			vector<llo> kx;
			kx.pb(su+su2);
			kx.pb(su+su3);
			sort(kx.begin(),kx.end());
			cout<<"! "<<kx[0]<<endl;
			string xy;
			cin>>xy;
			if(xy==":)"){
				return 0;
			}
			cout<<"! "<<kx[1]<<endl;
			string x2;
			cin>>x2;
			return 0;
		}
	}
	cout<<"! "<<ans<<endl;
	string xy;
	cin>>xy;

	






	return 0;
}