//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[1000001];
vector<llo> pre[101];
pair<llo,llo> ans[101];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
 	llo n,k;
 	cin>>n>>k;

 	for(llo i=0;i<n*k;i++){
 		cin>>it[i];
 		it[i]--;
 		pre[it[i]].pb(i);
 	}
 	llo cur=0;
 	while(cur<n){
 		vector<llo> xx;
 	
 		
 		for(llo i=0;i<k-1;i++){
 			if(cur==n){
 				break;
 			}
 			xx.pb(cur);
 			cur++;
 		}
 /*		for(auto j:xx){
 			cout<<j<<",";
 		}
 		cout<<endl;*/

 		llo aa=-1;
 		while(xx.size()){
 			pair<llo,llo> mi={1e8,-1};

 			for(auto j:xx){
 				llo xx=0;
 				vector<llo> dd;
 				for(auto i:pre[j]){
 					if(i>aa){
 						dd.pb(i);
 						xx++;
 					}
 					if(xx==2){
 						mi=min(mi,{i,j});
 					}
 				}
 			}
 			/*if(mi.b==-1){
 				cout<<11<<endl;
 				break;
 			}*/
 			vector<llo> dd;
			for(auto i:pre[mi.b]){
				if(i>aa){
					dd.pb(i);
				}
			}
			ans[mi.b]={dd[0],dd[1]};
			//cout<<dd[0]+1<<" "<<dd[1]+1<<endl;
 			vector<llo> yy;
 			aa=mi.a;
 			for(auto j:xx){
 				if(j!=mi.b){
 					yy.pb(j);
 				}
 			}
 			xx=yy;
 		}
 		//cout<<cur<<endl;

 	}
 	for(int i=0;i<n;i++){
 		cout<<ans[i].a+1<<" "<<ans[i].b+1<<endl;
 	}



 

 
 
 
	return 0;
}