//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo n;
llo it[200001];
llo st[200001];
vector<llo> adj[200001];
pair<llo,llo> ma[200001];
llo cur[200001];
llo ind=0;
llo endd[200001];
llo pre[200001];
llo pre2[200001];
void dfs(llo no,llo par=-1){
	ma[no]={0,no};
	st[no]=ind;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ma[no]=max(ma[no],ma[j]);
		}
	}
	if(ma[no].a==0){
		ma[no]={it[no],ind};
		cur[ind]=it[no];
		ind++;
	}
	else{	
		if(ma[no].a<it[no]){
			ma[no].a=it[no];
			cur[ma[no].b]=it[no];
		}
	}
	endd[no]=ind-1;
}
llo ma2[200001];
vector<llo> zz;
llo vis[200001];
void dfs2(llo no,llo par=-1){
	llo co=0;
	llo stt=0;

	for(auto j:adj[no]){
		if(j!=par){
			stt++;
			dfs2(j,no);
			ma2[no]=max(ma2[no],ma2[j]);
			
			if(ma2[j]>=it[no]){
				co++;
			}
		}
	}
	if(stt>0){

	}
	else{
		ma2[no]=cur[st[no]];
		co++;
	}
	llo zz2=0;
	if(st[no]>0){
		zz2=max(zz2,pre[st[no]]);
	}
	if(endd[no]+1<ind){
		zz2=max(zz2,pre2[endd[no]+1]);
	}
	if(zz2>=it[no]){
		co++;
	}
	if(co<2){
		zz.pb(no);
		vis[no]=1;
	}
}
llo ans=0;
llo cot=0;
void dfs3(llo no,llo par=-1){
	llo ok=-1;
	for(auto j:adj[no]){
		if(j!=par){
			if(no==zz[0]){
				if(ma2[j]<it[no]){
					for(llo x=st[j];x<=endd[j];x++){
						cot=max(cot,cur[x]);
					}
				}
				continue;
			}
			if(endd[j]<st[zz[0]] or st[j]>endd[zz[0]]){
				for(llo x=st[j];x<=endd[j];x++){
					cot=max(cot,cur[x]);
				}
			}
			else{
				ok=j;
			}
		}
	}
	if(it[no]>cot){
		ans+=it[no]-cot;
		cot=it[no];
	}
	if(ok>=0){
		dfs3(ok,no);
	}

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	if(n==2){
		cout<<max(it[0],it[1])*2<<endl;
		return 0;
	}

	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
	}
	llo x=0;
	for(llo i=0;i<n;i++){
		if(adj[i].size()>1){
			x=i;
			break;
		}
	}
	dfs(x);
	
	for(llo i=1;i<=ind;i++){
		pre[i]=max(pre[i-1],cur[i-1]);
	}
	for(llo i=ind-1;i>=0;i--){
		if(i<ind-1){
			pre2[i]=pre2[i+1];
		}
		pre2[i]=max(pre2[i],cur[i]);
	}

	dfs2(x);
	if(zz.size()){
		dfs3(x);
	}
	for(llo i=0;i<ind;i++){
		ans+=cur[i];
	}
	cout<<ans<<endl;


	


 
	return 0;
}