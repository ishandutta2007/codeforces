
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo n,m,k;
vector<llo> adj[500001];
llo vis[500001];
llo st=1;
llo it[500001];
vector<llo> tt;
void dfs(llo no,llo col=1){
	//cout<<vis[no]<<endl;
	vis[no]=col;
	tt.pb(no);
	///cout<<no<<","<<col<<endl;
	for(auto j:adj[no]){

		if(it[j]==it[no]){
			if(vis[j]==0){
			//	cout<<no<<','<<j<<endl;
				dfs(j,3-col);
			}
			else{
				if(vis[j]==vis[no]){
					st=0;
				}
			}
		}
	}
}
llo bb[500001];
llo vis2[500001];
llo vis3[1000001];
vector<llo> adj2[1000001];
llo st2=1;
void dfs2(llo no,llo col=1){
	vis3[no]=col;
	for(auto j:adj2[no]){
		if(vis3[j]==0){
			dfs2(j,3-col);
		}
		else{
			if(vis3[j]==vis3[no]){
				st2=0;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		it[i]--;
	}
	vector<pair<pair<llo,llo>,pair<llo,llo>>> ed;
	for(llo i=0;i<m;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		adj[aa].pb(bb);
		adj[bb].pb(aa);
		if(it[aa]!=it[bb]){
			ed.pb({{min(it[aa],it[bb]),max(it[aa],it[bb])},{aa,bb}});
		}
	}
	//set<llo> cot;
//	for(llo i=0;i<k;i++){
	//	cot.insert(i)
	//}
//	cout<<11<<endl;
	for(llo i=0;i<n;i++){
		if(vis[i]==0){
			st=1;
			tt.clear();
		//	cout<<i<<","<<endl;
			dfs(i);
			/*for(auto j:tt){
				cout<<j<<":";
			}
			cout<<endl;*/
			if(st==0){
		//		cot.erase(it[i]);
				vis2[it[i]]=1;
			}
			else{
				for(auto j:tt){
					bb[j]=i+(vis[j]-1)*n;
			//		bb[j]={i,vis[j]};
				}
			}
		}
	}
	sort(ed.begin(),ed.end());
	
	llo ind=0;
	llo so=0;
	for(llo i=0;i<k;i++){
		so+=1-vis2[i];
	}
	llo ans=((so*(so-1)))/2;
	//cout<<so<<"..."<<endl;
	while(ind<ed.size()){
		if(vis2[ed[ind].a.a] or vis2[ed[ind].a.b]){
			ind++;
			continue;
		}
		pair<llo,llo> tt=ed[ind].a;
		vector<llo> ee;
		//cout<<tt.a<<","<<tt.b<<endl;
		while(ind<ed.size()){
			if(ed[ind].a.a==tt.a and ed[ind].a.b==tt.b){
				llo cc=bb[ed[ind].b.a];
				llo dd=bb[ed[ind].b.b];
				adj2[cc].pb(dd);
				adj2[dd].pb(cc);
				//cout<<cc<<",,"<<dd<<endl;
				if(cc>=n){
					adj2[cc].pb(cc-n);
					adj2[cc-n].pb(cc);
					ee.pb(cc-n);
				}
				else{
					adj2[cc].pb(cc+n);
					adj2[cc+n].pb(cc);
					ee.pb(cc+n);
				}
				if(dd>=n){
					adj2[dd].pb(dd-n);
					adj2[dd-n].pb(dd);
					ee.pb(dd-n);
				}
				else{
					adj2[dd].pb(dd+n);
					adj2[dd+n].pb(dd);
					ee.pb(dd+n);
				}

				ee.pb(cc);
				ee.pb(dd);
				ind++;
			}
			else{
				break;
			}
		}
		st2=1;
		for(auto j:ee){
			if(vis3[j]==0){
				dfs2(j);
			}
		}
		for(auto j:ee){
			vis3[j]=0;
			adj2[j].clear();
		}
		if(st2==0){
			ans-=1;
		}

	}
	cout<<ans<<endl;











	return 0;
}