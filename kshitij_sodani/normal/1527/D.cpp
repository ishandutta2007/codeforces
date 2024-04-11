//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;
vector<llo> adj[200001];
llo st[200001];
llo endd[200001];
llo par[200001];
llo co=0;
llo ans[200001];
llo ss[200001];
llo lev[200001];
void dfs(llo no,llo par2=-1,llo levv=0){
	st[no]=co;
	co++;
	ss[no]=1;
	lev[no]=levv;
	for(auto j:adj[no]){
		if(j!=par2){
			dfs(j,no,levv+1);
			ss[no]+=ss[j];
		}
	}
	endd[no]=co-1;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			adj[i].clear();
		}
		for(llo i=0;i<=n;i++){
			ans[i]=0;
		}
		for(llo i=0;i<n-1;i++){
			llo aa,bb;
			cin>>aa>>bb;
			//aa--;
			//bb--;
			adj[aa].pb(bb);
			adj[bb].pb(aa);
		}
		co=0;
		dfs(0);
		//set<llo> xx;
		ans[0]=(n*(n-1))/2;
		pair<pair<llo,llo>,pair<llo,llo>> cur={{st[0],endd[0]},{st[0],endd[0]}};
		ans[1]=((n-1)*(n-2))/2;
		for(auto j:adj[0]){
			ans[1]-=((ss[j]*(ss[j]-1))/2);
		}
		ans[1]+=(n-1);
		llo su=1;
		llo tt=0;
		llo xx=-1;
		for(llo i=1;i<n;i++){
			/*if(cur.a.a<cur.b.a){
				swap(cur.a,cur.b);
			}*/
			//if(i>0){
		//	if(cur.)
				if(st[i]<=cur.a.a and endd[i]>=cur.a.b){

				}
				else if(st[i]<=cur.b.a and endd[i]>=cur.b.b){

				}
				else if(st[i]>=cur.a.a and endd[i]<=cur.a.b){
					if(i==1){

						for(auto j:adj[0]){
							if(st[j]<=st[i] and endd[j]>=endd[i]){
								xx=j;
							}
							else{
								su+=ss[j];
							}
						}
					}
					cur.a={st[i],endd[i]};
				}
				else if(st[i]>=cur.b.a and endd[i]<=cur.b.b){
					if(tt==0){
						llo zz=-1;
						//if(i==1){
							for(auto j:adj[0]){
								if(st[j]<=st[i] and endd[j]>=endd[i]){
									zz=j;
								}
								else{
									//su+=ss[j];
								}
							}
						//}
						//cout<<xx<<":"<<zz<<":"<<i<<endl;
						if(xx==zz){

							break;
						}
					}
					tt=1;
					cur.b={st[i],endd[i]};
				}
				else{
					break;
				}

				//cout<<i<<"::"<<endl;
			//}
			/*if(cur.a.a<cur.b.a){
				swap(cur.a,cur.b);
			}*/
				//cout<<i<<endl;
				//cout<<cur.a.a<<","<<cur.a.b<<","<<cur.b.a<<","<<cur.b.b<<endl;
				if(tt==0){
					ans[i+1]+=(su*(cur.a.b-cur.a.a+1));
					continue;
				}
		/*	if(cur.a.a>=cur.b.a and cur.a.b<=cur.b.b){
				ans[i+1]+=(su*(cur.a.b-cur.a.a+1));
				continue;
			}*/

			ans[i+1]=(cur.a.b-cur.a.a+1)*(cur.b.b-cur.b.a+1);

		}

		/*llo su=0;
		for(llo i=0;i<=n;i++){
			su+=ans[i];
		}*/
		/*for(llo i=0;i<=n;i++){
			cout<<ans[i]<<":";
		}
		cout<<endl;*/
		for(llo i=0;i<=n;i++){
			//if(i==n-1){
				if(i==n){
					cout<<ans[i]<<" ";
				}
				else{
					cout<<ans[i]-ans[i+1]<<" ";
				}
				//su+=ans[i];
			/*}
			else{

			}*/
		}
		//cout<<
		cout<<endl;
	}
 
 
 
	return 0;
}