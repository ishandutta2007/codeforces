//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
 
//#include "roads.h"
 
#include <vector>
vector<pair<llo,llo>> adj[250001];
vector<pair<llo,llo>> adj2[250001];
 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
 
 
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>
 
llo val[250001];
llo dp[250001][2];
vector<llo> tt[250001];
llo kk=-1;
llo vis[250001];
 
vector<llo> xx;
map<pair<llo,llo>,llo> ind;
vector<llo> tree2[250001];
vector<pair<pair<llo,llo>,llo>> pre[250001];
vector<llo> pre2[250001];
ord pre3[250001];
void update(llo zz,llo no,llo l,llo r,llo i,llo j){
	if(l==r){
		tree2[zz][no]=j;
	}
	else{
		llo mid=(l+r)/2;
		if(i<=mid){
			update(zz,no*2+1,l,mid,i,j);
		}
		else{
			update(zz,no*2+2,mid+1,r,i,j);
		}
		tree2[zz][no]=tree2[zz][no*2+1]+tree2[zz][no*2+2];
	}
}
llo query(llo zz,llo no,llo l,llo r,llo aa,llo bb){
	if(r<aa or l>bb){
		return 0;
	}
	if(aa<=l and r<=bb){
		return tree2[zz][no];
	}
	else{
		llo mid=(l+r)/2;
		return query(zz,no*2+1,l,mid,aa,bb)+query(zz,no*2+2,mid+1,r,aa,bb);
	}
}
void dfs(llo no,llo par2=-1,llo ba=-1){
	vector<llo> ss;
	llo su=0;
	vis[no]=1;
	vector<pair<llo,llo>> ne;
	vector<llo> tt;
	for(auto j:adj2[no]){
		if(j.a!=par2){
			if(adj[j.a].size()<kk){
			//	ne.pb(j);
			//	tt.pb(j.b);
				continue;
			}
			ne.pb(j);
			dfs(j.a,no,j.b);
			su+=dp[j.a][0];//not removed
			ss.pb(dp[j.a][1]-dp[j.a][0]);
			//ss.pb(j.a);
		}
		else{
			ne.pb(j);
		}
	}
	adj2[no]=ne;
	//cout<<no<<"::"<<ss.size()<<endl;
	/*for(auto j:tt[no]){
		ss.pb(j);
	}*/
	sort(ss.begin(),ss.end());
	//sort(tt.begin(),tt.end());
	dp[no][0]=1e14;
	dp[no][1]=1e14;
	for(llo i=0;i<2;i++){
		if(i==1 and par2==-1){
			continue;
		}
		llo nee=0;
		//cout<<11<<endl;
		for(llo ii=0;ii<=ss.size();ii++){
			if(ii>0){
				nee+=ss[ii-1];
			}
			llo ka=0;
			llo le=ss.size()+pre3[no].size();
			if(par2>=0 and i==0){
				le++;
			}
			/*if(kk>1){
				cout<<le<<"///"<<endl;
			}
*/
			le-=kk;
			le-=ii;
			/*if(le>0){
				continue;
			}*/
			/*if(kk>1){
				cout<<le<<"///"<<endl;
			}
			if(kk>1){
					cout<<endl;
					cout<<no<<":"<<le<<":"<<pre3[no].size()<<endl;
					for(auto j:pre3[no]){
						cout<<j<<"...";
					}
					cout<<endl;
					//cout<<ka<<"!"<<endl;
					//cout<<ind5<<".."<<endl;
			}*/
 
			if(le>(llo)pre3[no].size()){
				//dp[no][i]=ba+su;
				continue;
			}
 
			ka=su+nee;
 
		/*	for(llo j=0;j<le;j++){
				ka+=ss[j];
			}*/
			if(le>0){
				/*for(int j=0;j<le;j++){
					ka+=tt[j];
				}*/
				llo ind5=*pre3[no].find_by_order(le-1);
				ka+=query(no,0,0,adj[no].size()-1,0,ind5);
				/*for(int j=0;j<=ind5;j++){
					ka+=query(no,0,0,adj[no].size()-1,j,j);
				}*/
				//ka+=query(no,0,0,adj[no].size()-1,0,ind5);
				/*if(kk>1 ){
					cout<<111<<":"<<ind5<<endl;
					cout<<query(no,0,0,adj[no].size()-1,0,ind5)<<endl;
				}*/
				
			}
 
			
			if(i==1){
				ka+=ba;
			}
			//cout<<pre3[no].size()<<"..."<<endl;
			/*if(kk==1 and no==0){
				cout<<no<<":"<<i<<","<<ii<<":"<<ka<<endl;
				
			}*/
			dp[no][i]=min(dp[no][i],ka);
		}
 
	}
	dp[no][0]=min(dp[no][0],dp[no][1]);
 
	/*if(kk==1){
		cout<<no<<":"<<dp[no][0]<<":"<<dp[no][1]<<endl;
	}*/
 
}
 
vector<llo> minimum_closure_costs(int n,vector<int> aa,
                                             vector<int> bb,
                                             vector<int> cc) {
 
	vector<llo> ans;
	vector<llo> dd;
	for(llo i=0;i<n-1;i++){
		adj[aa[i]].pb({bb[i],cc[i]});
		adj[bb[i]].pb({aa[i],cc[i]});
		adj2[aa[i]].pb({bb[i],cc[i]});
		adj2[bb[i]].pb({aa[i],cc[i]});
		dd.pb(cc[i]);
	}
	//dfs(0);
	llo cot=0;
	for(llo i=0;i<n;i++){
		vector<pair<llo,llo>> dd;
		for(auto j:adj[i]){
			dd.pb({j.b,j.a});
		}
		sort(dd.begin(),dd.end());
		llo yy=-1;
		for(auto j:dd){
			yy++;
			ind[{i,j.b}]=yy;
			xx.pb(j.a);
		}
		for(llo j=0;j<4*adj[i].size();j++){
			tree2[i].pb(0);
		}
		//build(0,0,adj[i].size()-1,)
	}
 
	for(llo i=0;i<n-1;i++){
		cot+=cc[i];
	}
	for(llo i=0;i<n-1;i++){
		llo x=aa[i];
		llo y=bb[i];
		if(adj[x].size()>adj[y].size()){
			swap(x,y);
		}
		//pre[adj[x].size()].pb({{x,y},cc[i]});
		if(adj[x].size()<adj[y].size()){
			pre[adj[x].size()+1].pb({{y,cc[i]},ind[{y,x}]});
		}
		else{
 
		}
 
	}
	for(llo i=0;i<n;i++){
		pre2[adj[i].size()+1].pb(i);
	}
	set<llo> cur;
	for(llo i=0;i<n;i++){
		cur.insert(i);
	}
	ans.pb(cot);
	for(llo i=1;i<=n-1;i++){
		for(auto j:pre2[i]){
			cur.erase(j);
 
		}
		kk=i;
		for(auto j:cur){
			vis[j]=0;
		}
 
		for(auto j:pre[i]){
			update(j.a.a,0,0,adj[j.a.a].size()-1,j.b,j.a.b);
			pre3[j.a.a].insert(j.b);
		}
		llo ans2=0;
		for(auto j:cur){
			if(vis[j]==0){
				dfs(j);
				ans2+=dp[j][0];
 
			}
			//cout<<j<<",";
		}
	//cout<<endl;
		ans.pb(ans2);
 
	}
	//ans.pb(cot);
 
	/*for(llo i=0;i<n;i++){
		if(i==0){
			ans.pb(cot);
			continue;
		}
 
		kk=i;
 
		for(llo j=0;j<n;j++){
			adj2[j].clear();
			tt[j].clear();
			vis[j]=0;
		}
		for(llo j=0;j<n;j++){
			for(auto k:adj[j]){
				if(adj[j].size()>i){
					if(adj[k.a].size()>i){
						adj2[j].pb(k);
					}
					else{
						tt[j].pb(k.b);
					}
				}
			}
		}
		llo ans2=0;
		for(llo j=0;j<n;j++){
			if(adj[j].size()>i){
				if(vis[j]==0){
					dfs(j);
					ans2+=dp[j][0];
				}
			}
		}
		//dfs(0);
		
		ans.pb(ans2);
	}*/
 
 
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int na;
	cin>>na;
	vector<int> dd,ee,ff;
	for(int i=0;i<na-1;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		dd.pb(aa);
		ee.pb(bb);
		ff.pb(cc);
	}
	vector<llo> ans2=minimum_closure_costs(na,dd,ee,ff);
	for(auto j:ans2){
		cout<<j<<" ";
	}
	cout<<endl;






	return 0;
}