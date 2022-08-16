//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[300001];
llo vis[1000010];
vector<llo> pre[1000010];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo ind=2;
	while(ind<=1000000){
		if(vis[ind]==0){
			for(llo i=ind;i<=1000000;i+=ind){
				vis[i]=1;
				pre[i].pb(ind);
			}
		}
		ind++;
	}
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		map<vector<llo>,llo> kk;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			vector<llo> ss;
			llo cur=it[i];
			for(auto j:pre[it[i]]){
				llo coo=0;
				while(cur%j==0){
					cur/=j;
					coo=coo^1;
				}
				if(coo==1){
					ss.pb(j);
				}
			}
			kk[ss]++;
		}
		llo co=0;
		for(auto j:kk){
			co=max(co,j.b);
		}
		llo cot=0;
		for(auto j:kk){
			if((j.a).size()==0){
				cot+=j.b;
				//cout<<11<<endl;
				continue;
			}
			if(j.b%2==0){
				cot+=j.b;
			}
			/*for(auto i:j.a){
				cout<<i<<":";
			}
			cout<<j.b<<endl;
			cout<<endl;*/
		}
		cot=max(cot,co);
		llo q;
		cin>>q;
		while(q--){
			llo w;
			cin>>w;
			if(w==0){
				cout<<co<<endl;
			}
			else{
				cout<<cot<<endl;
			}
		}
	}





 
	return 0;
}