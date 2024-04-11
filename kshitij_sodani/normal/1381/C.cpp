#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int it[100001];
vector<int> col[100010];
int vis[100001];
int ans[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,x,y;
		cin>>n>>x>>y;
		
		for(int i=1;i<=n+1;i++){
			col[i].clear();
			vis[i]=0;
		}

		for(int i=0;i<n;i++){
			cin>>it[i];
			vis[it[i]]=1;
			col[it[i]].pb(i);
		}
		int ind=-1;
		for(int i=1;i<=n+1;i++){
			if(vis[i]==0){
				ind=i;
			}
		}
		int st=1;
		set<pair<int,int>> ss;
		for(int i=1;i<=n+1;i++){
			if(col[i].size()){
				ss.insert({-col[i].size(),i});
			}
		}
		set<pair<int,int>> mm;
		for(int i=0;i<x;i++){
			pair<int,int> no=*ss.begin();
			ss.erase(no);
			no.a+=1;
			int xx=col[no.b].back();
			col[no.b].pop_back();
			if(i<x){

				ans[xx]=no.b;
			}
			/*else{
				ans[xx]=ind;
			}*/
			if(no.a<0){
				ss.insert(no);
			}
		}
		vector<pair<int,int>> le;
		for(auto j:ss){
			while(col[j.b].size()){
				le.pb({j.b,col[j.b].back()});
				col[j.b].pop_back();
			}
		}

		if(n>x){
			int sh=le.size()/2;
				int co=0;
			for(int i=0;i<n-x;i++){
				ans[le[i].b]=le[(i+sh)%(n-x)].a;
				if(ans[le[i].b]==le[i].a){
					co+=1;
				}
			}
			if(co>n-y){
				st=0;
			}
			else{

				int co2=(n-y)-co;

				for(int i=0;i<n-x;i++){
					if(ans[le[i].b]==le[i].a){
						ans[le[i].b]=ind;
					}
					else{
						if(co2){
							co2--;
							ans[le[i].b]=ind;
						}
					}
				}
			}
		}
	
		if(st==0){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
			for(int i=0;i<n;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}


	}
	





	return 0;
}