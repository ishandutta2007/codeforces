//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
llo vis[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,p;
		cin>>n>>p;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			vis[i]=0;
			ss.pb({it[i],i});
		}
		sort(ss.begin(),ss.end());
		llo ans=0;
		llo cot=0;
		for(auto j:ss){
			if(vis[j.b]==0){
				llo i=j.b;
				pair<llo,llo> cur={i,i};
				while(cur.b<n-1){
					if(vis[cur.b+1]==0){
						if((it[cur.b+1]%it[i])==0){
							cur.b++;
						}
						else{
							break;
						}
					}
					else{
						break;
					}
				}
				while(cur.a>0){
					if(vis[cur.a-1]==0){
						if((it[cur.a-1]%it[i])==0){
							cur.a--;
						}
						else{
							break;
						}
					}
					else{
						break;
					}
				}
				
				
				if(cur.a>0){
					if(vis[cur.a-1]==1 and (it[cur.a-1]%it[i])==0){
						cot--;
						ans+=min(p,it[i]);
					}
				}
				if(cur.b<n-1){
					if(vis[cur.b+1]==1 and (it[(cur.b+1)]%it[i]==0)){
						cot--;
						ans+=min(p,it[i]);
					}
				}

				cot++;
				for(llo k=cur.a;k<=cur.b;k++){
					vis[k]=1;
				}
				llo co=min(p,it[i]);
			//	cout<<cur.a<<":"<<cur.b<<endl;
				ans+=(cur.b-cur.a)*co;
			}
		}
		ans+=(cot-1)*p;
		cout<<ans<<endl;
	}



 
 
	return 0;
}