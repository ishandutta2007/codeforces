#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int aa[200001];
int dist[200001];
int vis[200001];
vector<int> adj2[200001];
int ss[200001];
vector<pair<int,int>> adj[200001];
void dfs(int no,int par=-1){
	ss[no]=1;
	for(auto j:adj[no]){
		if(vis[j.a]==0 and par!=j.a){
			dfs(j.a,no);
			ss[no]+=ss[j.a];
		}
	}
}
int zz;
int find(int no,int par=-1){
	for(auto j:adj[no]){
		if(vis[j.a]==0 and par!=j.a){
			if(ss[j.a]>(zz/2)){
				return find(j.a,no);
			}
		}
	}
	return no;
}
int ma[200001];
int mi[200001];
int lev[200001];
int lev2[200001];
int ans[200001];
int tt2[200001];
int st[200001];
int endd[200001];

int val3[200001];
int val4[200001];
int coo;
int pp;
vector<pair<int,pair<int,int>>> cur;
void dfs2(int no,int par=-1,int levv=0,int levv2=0){

	lev[no]=levv;
	lev2[no]=levv2;
	st[no]=coo;
	coo++;

	if(par==-1){
		val3[no]=1;
		val4[no]=1;
	}
	else{
		val3[no]=val3[par];
		val4[no]=val4[par];
		if(dist[no]<dist[par]){
			val3[no]=0;
		}
		if(dist[no]>dist[par]){
			val4[no]=0;
		}
	}
	if(par>=0){
		mi[no]=min(mi[par],lev2[no]);
		ma[no]=max(ma[par],lev2[no]);
	}
	else{
		mi[no]=0;
		ma[no]=0;
	}

	cur.pb({-lev2[no],{-1,no}});
	cur.pb({mi[no],{0,no}});
	for(auto j:adj[no]){
		if(vis[j.a]==0 and j.a!=par){
			dfs2(j.a,no,levv+1,levv2+j.b);
		}
	}
	endd[no]=coo-1;
}


llo f(llo x){
	if(x>=0){
		return 2*(x/2);
	}
	else{
		llo zz=(abs(x));
		if(zz%2==0){
			return x;
		}
		else{
			return x-1;

		}
	}
}
void dec(int no){
	dfs(no);
	zz=ss[no];
	no=find(no);
	cur.clear();
	coo=0;
	pp=no;
	dfs2(no);

	sort(cur.begin(),cur.end());
	reverse(cur.begin(),cur.end());

	for(int ii=0;ii<2;ii++){
	
		int maa=-1e9;
		llo maa2=-1e9;
		for(auto j:cur){
			int k=j.b.b;
			
			
			if(j.b.a==-1){
				if(val3[k]==0){
					continue;
				}

				if(ma[k]==lev2[k]){
					int su=lev[k];
					su+=maa2;
					su+=f(lev2[k]);
					if(abs(lev2[k])%2==1 and ii==1){
						su+=2;
					}
					
					ans[k]=max(ans[k],su);
					ans[k]=max(ans[k],lev[k]+maa);
				}
			}
			else{

				
				if(val4[k]==0){
					continue;
				}
				if((abs(lev2[k])%2)==ii){
					
					maa=max(maa,lev[k]+dist[k]);
					if(tt2[k]){
						maa2=max(maa2,dist[k]+lev[k]+f(lev2[k]));
						//update(0,0,zz-1,st[k],dist[k]+lev[k]+f(lev2[k]));
					}
				}
			}
		}
	}
	//build(0,0,zz-1);
	vis[no]=1;
	for(auto j:adj[no]){
		if(vis[j.a]==0){
			dec(j.a);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	queue<int> ss;
	for(int i=0;i<n;i++){
		cin>>aa[i];
		dist[i]=-1;
		if(aa[i]==1){
			dist[i]=0;
			ss.push(i);
		}
	}
	vector<pair<int,int>> ee;
	for(int i=0;i<n-1;i++){
		int aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		ee.pb({aa,bb});
		adj2[aa].pb(bb);
		adj2[bb].pb(aa);
	}
	while(ss.size()){
		int no=ss.front();
		ss.pop();
		for(auto j:adj2[no]){
			if(dist[j]==-1){
				dist[j]=dist[no]+1;
				ss.push(j);
			}
		}
	}
	for(auto j:ee){
		if(dist[j.a]==dist[j.b]){
			tt2[j.a]=1;
			tt2[j.b]=1;
			adj[j.a].pb({j.b,-1});
			adj[j.b].pb({j.a,-1});
		}
		else{
			adj[j.a].pb({j.b,1});
			adj[j.b].pb({j.a,1});
		}
	}
	dec(0);
	for(int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;




	return 0;
}