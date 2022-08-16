#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo mod=998244353;
 
vector<llo> adj[400001];
vector<llo> adj2[400001];
 
llo dist[200001*30];
pair<llo,llo> dist2[400001];
llo ee(llo aa,llo bb){
	if(bb==0){
		return 1;
	}
	llo ac=ee(aa,bb/2);
	ac=(ac*ac)%mod;
	if(bb%2==1){
		ac=(ac*aa)%mod;
	}
	return ac;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m;
	cin>>n>>m;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj2[bb].pb(aa);
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<30;j++){
			dist[j*n+i]=-1;
		}
	}
	dist[0]=0;
	priority_queue<pair<llo,llo>> ss;
	ss.push({-dist[0],0});
	while(ss.size()){
		pair<llo,llo> no=ss.top();
		ss.pop();
		no.a=-no.a;
	/*	if(no.b==7){
			cout<<no.a<<endl;
		}*/
		if(dist[no.b]!=no.a){
			continue;
		}
		if(((no.b)/n)%2==0){
			llo le=no.b-no.b%n;
			for(auto j:adj[no.b%n]){
				pair<llo,llo> xx={no.a+1,j+le};
				if(dist[xx.b]==-1 or dist[xx.b]>xx.a){
					dist[xx.b]=xx.a;
					xx.a=-xx.a;
					ss.push(xx);
				}
			}
			
			if(no.b/n<29){
				llo bb=(1LL<<((no.b)/n));
				pair<llo,llo> xx={no.a+bb,no.b+n};
				if(dist[xx.b]==-1 or dist[xx.b]>xx.a){
					dist[xx.b]=xx.a;
					xx.a=-xx.a;
					ss.push(xx);
				}
			}
		}
		else{
			llo le=no.b-no.b%n;
			for(auto j:adj2[no.b%n]){
				pair<llo,llo> xx={no.a+1,j+le};
				if(dist[xx.b]==-1 or dist[xx.b]>xx.a){
					dist[xx.b]=xx.a;
					xx.a=-xx.a;
					ss.push(xx);
				}
			}
			
			if(no.b/n<29){
				llo bb=(1LL<<((no.b)/n));
 
				pair<llo,llo> xx={no.a+bb,no.b+n};
				if(dist[xx.b]==-1 or dist[xx.b]>xx.a){
					dist[xx.b]=xx.a;
					xx.a=-xx.a;
					ss.push(xx);
				}
			}
		}
	}
	llo ans=-1;
	//cout<<dist[n]<<":"<<dist[2*n-1]<<endl;
	for(llo i=n-1;i<30*n;i+=n){
		if(dist[i]!=-1){
			//cout<<i<<":"<<dist[i]<<endl;
			if(ans==-1){
				ans=dist[i];
			}
			ans=min(ans,dist[i]);
		}
	}
	if(ans!=-1){
		ans%=mod;
		cout<<ans<<endl;
		return 0;
	}
	for(llo i=0;i<2*n;i++){
		dist2[i]={-1,-1};
	}
 
	dist2[0]={0,0};
 
	priority_queue<pair<pair<llo,llo>,llo>> tt;
	tt.push({dist2[0],0});
	while(tt.size()){
		pair<pair<llo,llo>,llo> no=tt.top();
		tt.pop();
		no.a.a=-no.a.a;
		no.a.b=-no.a.b;
		if(dist2[no.b].a!=no.a.a or dist2[no.b].b!=no.a.b){
			continue;
		}
		if(((no.b)/n)%2==0){
			llo le=no.b-no.b%n;
			for(auto j:adj[no.b%n]){
				pair<pair<llo,llo>,llo> xx={{no.a.a,no.a.b+1},j+le};
				if(dist2[xx.b].a==-1 or dist2[xx.b].a>xx.a.a or (dist2[xx.b].a==xx.a.a and dist2[xx.b].b>xx.a.b)){
					dist2[xx.b]=xx.a;
					xx.a.a=-xx.a.a;
					xx.a.b=-xx.a.b;
					tt.push(xx);
				}
			}
			pair<pair<llo,llo>,llo> xx={{no.a.a+1,no.a.b},no.b+n};
			if(dist2[xx.b].a==-1 or dist2[xx.b].a>xx.a.a or (dist2[xx.b].a==xx.a.a and dist2[xx.b].b>xx.a.b)){
				dist2[xx.b]=xx.a;
				xx.a.a=-xx.a.a;
				xx.a.b=-xx.a.b;
				tt.push(xx);
			}
		}
		else{
			llo le=no.b-no.b%n;
			for(auto j:adj2[no.b%n]){
				pair<pair<llo,llo>,llo> xx={{no.a.a,no.a.b+1},j+le};
				if(dist2[xx.b].a==-1 or dist2[xx.b].a>xx.a.a or (dist2[xx.b].a==xx.a.a and dist2[xx.b].b>xx.a.b)){
					dist2[xx.b]=xx.a;
					xx.a.a=-xx.a.a;
					xx.a.b=-xx.a.b;
					tt.push(xx);
				}
			}
			pair<pair<llo,llo>,llo> xx={{no.a.a+1,no.a.b},no.b-n};
			if(dist2[xx.b].a==-1 or dist2[xx.b].a>xx.a.a or (dist2[xx.b].a==xx.a.a and dist2[xx.b].b>xx.a.b)){
				dist2[xx.b]=xx.a;
				xx.a.a=-xx.a.a;
				xx.a.b=-xx.a.b;
				tt.push(xx);
			}
		}
	}
 
	pair<llo,llo> fin=dist2[n-1];
	if(dist2[2*n-1].a<fin.a or (dist2[2*n-1].a==fin.a and dist2[2*n-1].b<fin.b)){
		fin=dist2[2*n-1];
	}
	llo cot=(ee(2,fin.a)-1+mod)%mod;
	cot=(cot+fin.b)%mod;
	cout<<cot<<endl;
 
 
 
 
 
	return 0;
}