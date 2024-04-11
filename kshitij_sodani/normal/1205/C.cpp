//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
int n;
int it[101][101];
bool ask(int aa,int bb,int cc,int dd){
	if(aa>cc or bb>dd){
		swap(aa,cc);
		swap(bb,dd);
	}
	cout<<"? "<<aa+1<<" "<<bb+1<<" "<<cc+1<<" "<<dd+1<<endl;
	int x;
	cin>>x;
	return x;
}
vector<pair<int,int>> adj[101][101];
void dfs(int i,int j){
	for(auto ii:adj[i][j]){
		if(it[ii.a][ii.b]==-1){
			it[ii.a][ii.b]=it[i][j]^(1-ask(i,j,ii.a,ii.b));
			dfs(ii.a,ii.b);
		}
	}
}
void flip(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((i+j)%2==1){
				it[i][j]=1-it[i][j];
			}
		}
	}
}
void pp(){
	cout<<"!"<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<it[i][j];
		}
		cout<<endl;
	}
}
void cot(int aa,int bb){
	int cc=aa+1;
	int dd=bb+2;
	if(ask(aa,bb,cc,dd)){
		if(it[aa][bb]!=it[cc][dd]){
			flip();
		}
	}
	else{
		if(it[aa][bb]==it[cc][dd]){
			flip();
		}
	}
	pp();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			it[i][j]=-1;
		}
	}
	it[n-1][n-1]=0;
	it[n-2][n-1]=0;



	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			vector<pair<int,int>> kk;
			kk.pb({i+1,j+1});
			kk.pb({i,j+2});
			kk.pb({i+2,j});
			for(auto jj:kk){
				if(jj.a<n and jj.b<n){
					adj[i][j].pb(jj);
					adj[jj.a][jj.b].pb({i,j});
				}
			}
		}
	}

	dfs(n-1,n-1);
	dfs(n-2,n-1);
//	return 0;
	
	//pp();
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pair<int,int> ii={i+1,j-1};
			if(ii.a<0 or ii.a>=n or ii.b<0 or ii.b>=n){
				continue;
				
			}
			/*if((i+j)%2==1){
				continue;
			}*/
			if(it[i][j]!=it[ii.a][ii.b]){
					if(j==n-1){
						cot(min(ii.a,i),min(ii.b,j)-1);
						return 0;
					}
					else{
						cot(min(ii.a,i),min(ii.b,j));
						return 0;
					}
				}
		}
	}
	vector<pair<int,int>> ss;
	for(int i=0;i<n;i++){
		ss.pb({0,i});
	}
	for(int i=1;i<n;i++){
		ss.pb({i,n-1});
	}

	for(int i=0;i<2*n;i+=2){
		set<int> tt;
		tt.insert(it[ss[i].a][ss[i].b]);
		tt.insert(it[ss[i+2].a][ss[i+2].b]);
		tt.insert(it[ss[i+4].a][ss[i+4].b]);
		if(it[ss[i].a][ss[i].b]==it[ss[i+2].a][ss[i+2].b] or (it[ss[i+2].a][ss[i+2].b]==it[ss[i+4].a][ss[i+4].b])){


			if(ask(ss[i].a,ss[i].b,ss[i+3].a,ss[i+3].b)){
				if(it[ss[i].a][ss[i].b]!=it[ss[i+3].a][ss[i+3].b]){
					flip();
				}
				pp();
				return 0;
			}
			if(ask(ss[i+1].a,ss[i+1].b,ss[i+4].a,ss[i+4].b)){
				if(it[ss[i+1].a][ss[i+1].b]!=it[ss[i+4].a][ss[i+4].b]){
					flip();
				}
				pp();
				return 0;
			}
			pair<int,int> aa={it[ss[i+2].a][ss[i+2].b],it[ss[i].a][ss[i].b]};
			pair<int,int> bb={it[ss[i+4].a][ss[i+4].b],it[ss[i+2].a][ss[i+2].b]};
		
			if(aa.a==bb.a){
				if(it[ss[i+1].a][ss[i+1].b]==aa.a){
					flip();
				}

				pp();
				return 0;
			}
			else if(aa.b==bb.b){
				if(it[ss[i+3].a][ss[i+3].b]==aa.b){
					flip();
				}


				pp();
				return 0;
			}
			else{
				while(true){
					continue;
				}
			}

		}
	}

	


 
 
 
 
	return 0;
}