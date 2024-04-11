#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo n,q;
vector<pair<llo,llo>> pre[100001];
vector<pair<llo,llo>> pre2[100001];

llo co[100001][30];
llo ans[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>q;
	for(llo i=0;i<n;i++){
		ans[i]=-1;
	}
	vector<pair<pair<llo,llo>,llo>> ss;
	for(llo ii=0;ii<q;ii++){
		llo i,j,aa;
		cin>>i>>j>>aa;
		i--;
		j--;
		for(llo jj=0;jj<30;jj++){
			if((1<<jj)&aa){

			}
			else{
				co[i][jj]=1;
				co[j][jj]=1;
			}
		}
		if(i==j){
			ans[i]=aa;
		}
		else{
			if(i>j){
				swap(i,j);
			}
			pre[i].pb({j,aa});
			pre2[j].pb({i,aa});
		}
	}
	
	for(llo i=0;i<n;i++){
		llo su=0;
		for(auto j:pre[i]){
			for(llo k=0;k<30;k++){
				if((1<<k)&j.b){
					if(co[j.a][k]==1){
						su|=(1<<k);
					}
				}
			}
		}
		for(auto j:pre2[i]){
			for(llo k=0;k<30;k++){
				if((1<<k)&j.b){
					if((ans[j.a]&(1<<k))==0){
						su|=(1<<k);
					}
				}
			}
		}
		if(ans[i]==-1){
			ans[i]=su;
		}
	}
	for(llo i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;






	return 0;
}