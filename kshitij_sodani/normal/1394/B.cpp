#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n,m,k;
//int val[10][10];
//int cot[10][10];
vector<pair<pair<int,int>,int>> adj[200001];
vector<pair<pair<int,int>,int>> adj2[200001];
int val[200001];
int mat[10][10][10][10];
int ans=0;
/*int vis[10][10];
int vis2[10][10];*/
//bitset<200001> ac[10][10];
//bitset<200001> cur3;
int vis5[10][10];
vector<pair<int,int>> adj3[10][10];
int coc=0;
int cot[10][10];
int vis6[10][10];
vector<int> cur;
void brute(int ind){
	if(ind==k){
		for(int j=0;j<k-1;j++){
			for(int i=j+1;i<k;i++){
				if(mat[i+1][cur[i]][j+1][cur[j]]){
					return;
				}
			}
		}
		if(coc==n){
			ans+=1;
		}
	}
	else{
		for(int i=1;i<=ind+1;i++){
			if(vis6[ind+1][i]){
				continue;
			}
			cur.pb(i);
			coc+=cot[ind+1][i];
		/*	for(auto j:adj3[ind+1][i]){
				vis5[j.a][j.b]+=1;
			}*/
			brute(ind+1);
			coc-=cot[ind+1][i];
			cur.pop_back();
			/*for(auto j:adj3[ind+1][i]){
				vis5[j.a][j.b]-=1;
			}*/
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	/*for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			val[i][j]=1;
		}
	}*/
	for(int i=0;i<m;i++){
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		adj[aa].pb({{cc,bb},i});
		adj2[bb].pb({{cc,aa},i});
	}
	for(int i=0;i<n;i++){
		sort(adj[i].begin(),adj[i].end());
		sort(adj2[i].begin(),adj2[i].end());
		int x=0;
		for(auto j:adj[i]){
			x++;
			val[j.b]=x;
		}
	}
	for(int i=0;i<n;i++){
		set<pair<int,int>> xt;
		set<pair<int,int>> xt2;
		for(auto j:adj2[i]){
			if(xt.find({adj[j.a.b].size(),val[j.b]})!=xt.end()){
				xt2.insert({adj[j.a.b].size(),val[j.b]});
				continue;
			}
			xt.insert({adj[j.a.b].size(),val[j.b]});
		}
		for(auto j:xt2){
			vis6[j.a][j.b]=1;
		}
		for(auto j:xt){
			//ac[j.a][j.b].set(i);
			cot[j.a][j.b]+=1;
		//	cout<<j.a<<":"<<j.b<<":"<<i<<endl;
		}

		//cout<<endl;

		/*for(int j=1;j<=k;j++){
			for(int kk=1;kk<=j;kk++){
				vis[j][kk]=0;
			}
		}	
		for(auto j:xt){
			vis[j.a][j.b]=1;
		}*/

		vector<pair<int,int>> xx;
		for(auto j:xt){
			xx.pb(j);
		}

		for(int j=0;j<xx.size();j++){
			for(int kk=0;kk<xx.size();kk++){
				mat[xx[j].a][xx[j].b][xx[kk].a][xx[kk].b]=1;
			}
		}

	}
/*	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++){
			for(int kk=i;kk<=k;kk++){
				for(int ll=1;ll<=kk;ll++){
					if(i==kk and j==ll){
						continue;
					}
					if((ac[i][j]&ac[kk][ll]).count()){
						adj3[i][j].pb({kk,ll});
					}
				}
			}
		}
	}*/
	brute(0);
	cout<<ans<<endl;




	return 0;
}