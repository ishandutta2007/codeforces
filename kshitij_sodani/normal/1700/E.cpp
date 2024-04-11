#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
int n,m;
vector<int> it[400001];
int vis[400001];
vector<int> x={-1,1,0,0};
vector<int> y={0,0,1,-1};
vector<pair<int,int>> ne[400001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int aa;
			cin>>aa;
			it[i].pb(aa);
		}
	}
	vector<pair<int,int>> ss;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			
			int st=0;
			for(int ii=0;ii<4;ii++){
				int xx=i+x[ii];
				int yy=j+y[ii];

				if(xx<0 or yy<0 or xx>=n or yy>=m){
					continue;
				}
				ne[i*m+j].pb({xx,yy});
				if(it[i][j]==1){
					continue;
				}
				if(it[xx][yy]<it[i][j]){
					st=1;
				}
			}
			if(it[i][j]==1){
				continue;
			}
			if(st==0){
				ss.pb({i,j});
			}
		}
	}
	if(ss.size()==0){
		cout<<0<<endl;
		return 0;
	}
	if(ss.size()>6){
		cout<<2<<endl;
		return 0;
	}
	set<pair<int,int>> tt;
	vector<pair<int,int>> cur2;
	for(auto j:ss){
		if(j==ss.back()){
			cur2.pb(j);
			for(auto i:ne[j.a*m+j.b]){
				cur2.pb(i);
			}
		}
		tt.insert(j);
		for(auto i:ne[j.a*m+j.b]){
			tt.insert(i);
		}
	}
	vector<pair<int,int>> cur;
	
	for(auto j:tt){
		cur.pb(j);
		vis[j.a*m+j.b]=1;
	}
	int ans=0;
	for(int i=0;i<cur.size();i++){

		for(int j=i+1;j<cur.size();j++){
			swap(it[cur[i].a][cur[i].b],it[cur[j].a][cur[j].b]);
			int ok=0;
			ss.pb(cur[i]);
			ss.pb(cur[j]);
			for(auto jj:ne[cur[i].a*m+cur[i].b]){
				ss.pb(jj);
			}
			for(auto jj:ne[cur[j].a*m+cur[j].b]){
				ss.pb(jj);
			}
			for(auto jj:ss){
				int st=1;
				if(it[jj.a][jj.b]==1){
					continue;
				}
				for(auto kk:ne[jj.a*m+jj.b]){
					if(it[kk.a][kk.b]<it[jj.a][jj.b]){
						st=0;
						break;
					}
				}	
				ok+=st;
			}
			ss.pop_back();
			ss.pop_back();
			for(auto jj:ne[cur[i].a*m+cur[i].b]){
				ss.pop_back();
			}
			for(auto jj:ne[cur[j].a*m+cur[j].b]){
				ss.pop_back();
			}
			if(ok==0){
				ans++;
			}
			swap(it[cur[i].a][cur[i].b],it[cur[j].a][cur[j].b]);
		}
	}
	for(auto j:cur2){
		for(int ii=0;ii<n*m;ii++){
			if(vis[ii]==0){
				pair<int,int> i={ii/m,ii%m};
				swap(it[j.a][j.b],it[i.a][i.b]);

				int ok=0;
				ss.pb(i);
				ss.pb(j);
				for(auto jj:ne[i.a*m+i.b]){
					ss.pb(jj);
				}
				for(auto jj:ne[j.a*m+j.b]){
					ss.pb(jj);
				}

				for(auto jj:ss){
					int st=1;
					if(it[jj.a][jj.b]==1){
						continue;
					}
					for(auto kk:ne[jj.a*m+jj.b]){
						if(it[kk.a][kk.b]<it[jj.a][jj.b]){
							st=0;
							break;
						}
					}	
				
					ok+=st;
				}

				ss.pop_back();
				ss.pop_back();
				for(auto jj:ne[i.a*m+i.b]){
					ss.pop_back();
				}
				for(auto jj:ne[j.a*m+j.b]){
					ss.pop_back();
				}
				if(ok==0){
					ans++;
				//	cout<<it[cur[i].a][cur[i].b]<<":"<<it[cur[j].a][cur[j].b]<<endl;
				}




				swap(it[j.a][j.b],it[i.a][i.b]);
			}
		}
	}
 	if(ans==0){
 		cout<<2<<endl;
 	}
 	else{
 		cout<<1<<" "<<ans<<endl;
 	}
 
 
	return 0;
}