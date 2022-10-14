#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back

int it[10001];
int par[10001];
int find(int no){
	if(par[no]==no){
		return no;
	}
	par[no]=find(par[no]);
	return par[no];
}
int vis[10001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			par[i]=i;
			vis[i]=0;
		}
		vector<pair<int,int>> ss;
		for(int i=0;i<n;i++){
			cin>>it[i];
			ss.pb({it[i],i});
		}
		sort(ss.begin(),ss.end());
		reverse(ss.begin(),ss.end());
		for(int i=0;i<ss.size();i++){
			int aa=ss[i].b;
			if(vis[aa]==0){
				vis[aa]=1;
				for(int j=0;j<ss[i].a;j++){
					cout<<"? "<<aa+1<<endl;
					int x;
					cin>>x;
					x--;

					if(vis[find(x)]==1){
						par[aa]=find(x);
						break;
					}
					vis[x]=1;
				//	cout<<x<<","<<aa<<endl;
					par[x]=aa;
				}
			}

		}

		cout<<"! ";
		for(int i=0;i<n;i++){
			cout<<find(i)+1<<" ";
		}
		cout<<endl;

	}
	



	return 0;
}