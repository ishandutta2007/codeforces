#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
llo n;
llo it[30][30];
llo vis[30][30];
llo back[30][30];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		for(llo j=0;j<n;j++){
			if(i%2==0){
				it[i][j]=((llo)1<<(i+j));
			}
			cout<<it[i][j]<<" ";
		}
		cout<<endl;
	}
	llo q;
	cin>>q;
	while(q--){
		llo x;
		cin>>x;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<n;j++){
				vis[i][j]=0;
				if(x&((llo)1<<(i+j))){
					if(i%2==0){
						vis[i][j]=1;
					}
				}
				else{
					if(i%2==1){
						vis[i][j]=1;
					}
				}
				back[i][j]=0;
				if(i==0 and j==0){
					back[i][j]=1;
					continue;
				}
				if(vis[i][j]){
					if(i>0){
						if(back[i-1][j]){
							back[i][j]=1;
						}
					}
					if(j>0){
						if(back[i][j-1]){
							back[i][j]=2;
						}
					}
				}
			}
		}
		vector<pair<llo,llo>> ans;
		ans.pb({n-1,n-1});
		for(llo i=0;i<2*n-2;i++){
			if(back[ans.back().a][ans.back().b]==1){
				ans.pb({ans.back().a-1,ans.back().b});
			}
			else{
				ans.pb({ans.back().a,ans.back().b-1});
			}
		}
		while(ans.size()){
			cout<<ans.back().a+1<<" "<<ans.back().b+1<<endl;
			ans.pop_back();
		}


	}




	return 0;
	
}