#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
int par[200001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int ans[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			par[i]=i;
		}
		vector<pair<pair<int,int>,int>> ss;
		map<int,int> kk;
		vector<pair<pair<int,int>,int>> kk2;
		for(int i=0;i<m;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			kk2.pb({{aa,bb},i});
			int x=find(aa);
			int y=find(bb);
			if(x==y){
				ss.pb({{aa,bb},i});
				kk[aa]++;
				kk[bb]++;
				ans[i]=1;
			}
			else{
				par[x]=y;
				ans[i]=0;

			}
		}
		int st=1;
		if(ss.size()==3){
			for(auto j:kk){
				if(j.b!=2){
					st=0;
				}
			}
			if(st==1){
				for(int i=0;i<n;i++){
					par[i]=i;
				}
				int xx=find(ss[0].a.a);
				int yy=find(ss[0].a.b);
				par[xx]=yy;
				ans[ss[0].b]=0;
				for(auto i:kk2){
					if(i.b==ss[0].b){
						continue;
					}
					if(i.b==ss[1].b or i.b==ss[1].b){
						continue;
					}
					int aa=i.a.a;
					int bb=i.a.b;
					int x=find(aa);
					int y=find(bb);
					if(x==y){
						ans[i.b]=1;
					}
					else{
						par[x]=y;
						ans[i.b]=0;
					}
				}
				for(int i=0;i<m;i++){
					cout<<ans[i];
				}
				cout<<endl;
				continue;
			}
		}
		for(int i=0;i<m;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}






	return 0;
}