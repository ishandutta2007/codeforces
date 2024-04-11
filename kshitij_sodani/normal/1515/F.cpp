//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


llo n,m,x;
llo it[300001];
vector<pair<llo,llo>> adj[300001];
llo vis[300001];
llo par[300001];
llo val[300001];
llo dd[300001];
llo find(llo no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>x;
	//pair<llo,llo> ma={-1,-1};
	//vector<pair<llo,llo>> ss;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		par[i]=i;
		val[i]=it[i];
		//ss.pb({it[i],i});
	//	ma=max(ma,{it[i],i});
	}
	//sort(ss.begin(),ss.end());
	//reverse(ss.begin(),ss.end());
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		llo x=find(aa);
		llo y=find(bb);
		if(x==y){
			continue;
		}
		par[x]=y;
		adj[aa].pb({bb,i});
		adj[bb].pb({aa,i});
	}
	for(llo i=0;i<n;i++){
		if(find(i)!=find(0)){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for(llo i=0;i<n;i++){
		par[i]=i;
	}
	llo cot=0;
	vector<llo> ans;
	queue<llo> ss;
	for(llo i=0;i<n;i++){
		dd[i]=adj[i].size();
		
		if(adj[i].size()==1){
			ss.push(i);
			//vis[i]=1;
		}
	}
	llo su=0;
	for(llo i=0;i<n;i++){
		su+=it[i];
	}
	su-=(n-1)*x;
	if(su<0){
		cout<<"NO"<<endl;
		return 0;
	}
	//cout<<"YES"<<endl;
	vector<llo> ans2;

	while(ss.size()){
		llo no=ss.front();
		ss.pop();
		if(vis[no]==1){
			continue;
		}
		cot++;
		if(cot==n){
			break;
		}
		vis[no]=1;
		llo xx=find(no);
		pair<llo,llo> ne={-1,-1};
		for(auto j:adj[no]){
			if(vis[j.a]==0){
				assert(ne.a==-1);
				ne=j;
				dd[j.a]--;
				if(dd[j.a]==1){
					//vis[j.a]=1;
					ss.push(j.a);
				}
			}
		}
		if(ne.a==-1){
			while(true){
				continue;
			}
		}
		llo yy=find(ne.a);
		if(val[xx]>=x){
	
			par[xx]=yy;
			val[yy]=val[xx]+val[yy]-x;
			ans.pb(ne.b);
		}
		else{
			ans2.pb(ne.b);
		}
	}
	while(ans2.size()){
		ans.pb(ans2.back());
		ans2.pop_back();
	}
	/*for(auto j:ss){
		vector<pair<llo,pair<llo,llo>>> tt;
		for(auto i:adj[j.b]){
			if(vis[i.a]==1){
				llo x=find(i.a);
				tt.pb({val[x],{x,i.b}});
			}
		}
		if(tt.size()){
			sort(tt.begin(),tt.end());
			reverse(tt.begin(),tt.end());
			for(llo i=0;i<tt.size();i++){
				if(i>0){
					if(tt[i].b.a==tt[i-1].b.a){
						continue;
					}
				}
				if(val[j.b]+tt[i].a<x){
					break;
				}
				par[tt[i].b.a]=j.b;
				val[j.b]=val[j.b]+tt[i].a-x;
				ans.pb(tt[i].b.b);
			}
		}
		vis[j.b]=1;
	}*/
	/*if(ans.size()<n-1){
		cout<<"NO"<<endl;
		return 0;
	}*/
	cout<<"YES"<<endl;
	for(auto j:ans){
		cout<<j+1<<endl;
	}
/*	priority_queue<pair<pair<llo,llo>,llo>> pp;
	vis[ma.b]=1;
	for(auto j:adj[ma.b]){
		if(vis[j.a]==0){
			pp.push({{it[j.a],j.b},j.a});
		}
	}
	vector<llo> ans;
	llo cur=it[ma.b];
	while(pp.size()){
		pair<pair<llo,llo>,llo> no=pp.top();
		pp.pop();
		if(vis[no.b]==1){
			continue;
		}
		ans.pb(no.a.b);
		if(cur+it[no.b]<x){
			cout<<"NO"<<endl;
			return 0;
		}
		vis[no.b]=1;
		cur=cur+it[no.b]-x;
		for(auto j:adj[no.b]){
			if(vis[j.a]==0){
				pp.push({{it[j.a],j.b},j.a});
			}
		}
		//an

	}
	cout<<"YES"<<endl;
	for(auto j:ans){
		cout<<j+1<<endl;
	}
*/










	return 0;
}