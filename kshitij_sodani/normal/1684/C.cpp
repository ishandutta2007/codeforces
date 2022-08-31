#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
vector<int> it[200001];
int le[200001];
int re[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			it[i].clear();
			for(int j=0;j<m;j++){
				int cc;
				cin>>cc;
				it[i].pb(cc);
			}
		}
		for(int j=0;j<m;j++){
			le[j]=j;
			if(j>0){
				int ok=0;
				for(int i=0;i<n;i++){
					if(it[i][j]==it[i][j-1]){
						ok++;
					}
				}
				if(ok==n){
					le[j]=le[j-1];
				}
			}
		}
		for(int j=m-1;j>=0;j--){
			re[j]=j;
			if(j+1<m){
				if(le[j+1]<=j){
					re[j]=re[j+1];
				}
			}
		}
		set<int> ee;
		for(int i=0;i<m-1;i++){
			int st=1;
			for(int j=0;j<n;j++){
				if(it[j][i]>it[j][i+1]){
					st=0;
					break;
				}
			}
			if(st==0){
				ee.insert(i);
				ee.insert(i+1);
				ee.insert(le[i]);
				ee.insert(re[i+1]);
			}
		}
		if(ee.size()>10){
			cout<<-1<<" "<<endl;
			continue;
		}
		if(ee.size()==0){
			cout<<1<<" "<<1<<endl;
			continue;
		}
		/*vector<int> tt;
			tt.pb(ind);
			tt.pb(ind+1);*/
			pair<llo,llo> ans={-1,-1};
		for(auto i:ee){

			for(auto jj:ee){
				if(jj<i){
					continue;
				}
				for(int k=0;k<n;k++){
					swap(it[k][i],it[k][jj]);
				}
				llo ok=0;
				for(int ii=0;ii<m-1;ii++){
					for(int j=0;j<n;j++){
						if(it[j][ii]>it[j][ii+1]){
							ok=1;
						}
					}
				}
				if(ok==0){
					ans={i,jj};
				}

				for(int k=0;k<n;k++){
					swap(it[k][i],it[k][jj]);
				}
			}
			if(ans.a>=0){
				break;
			}
		}
		if(ans.a==-1){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans.a+1<<" "<<ans.b+1<<endl;
	}


	







	return 0;
}