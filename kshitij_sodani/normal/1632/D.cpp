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
llo zz[200001];
vector<pair<llo,llo>> pre[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	pre[n-1].pb({it[n-1],n-1});
	for(llo i=n-2;i>=0;i--){
		pre[i].pb({it[i],i});
		for(auto j:pre[i+1]){
			llo jj=__gcd(j.a,it[i]);
			if(jj!=pre[i].back().a){
				pre[i].pb({jj,j.b});
			}
			else{
				continue;
			}
		}

	}
	for(llo i=n-1;i>=0;i--){
		llo ind=-1;
		zz[i]=-1;
		for(auto j:pre[i]){
			ind++;
			//j in range 
			llo re=n-1;
			if(ind+1<pre[i].size()){
				re=pre[i][ind+1].b-1;
			}
			//j.a in range (j.b,re+1);
			if(j.a>=(j.b-i+1) and j.a<=(re-i+1)){
				zz[i]=i+j.a-1;
				break;
			}
		}
	}
	set<pair<llo,llo>> cur;
	llo ind=0;
	for(llo i=0;i<n;i++){
		if(zz[i]!=-1){
			cur.insert({zz[i],i});
		}
	}
	while(ind<n){
		if(cur.size()){
			pair<llo,llo> no=*(cur.begin());
			for(llo j=ind;j<=no.a;j++){
				if(zz[j]>=0){
					cur.erase({zz[j],j});
				}
			}
			vis[no.a]=1;
			ind=no.a+1;
		}
		else{
			break;
		}
	}



	llo ans=0;
	for(llo i=0;i<n;i++){
		ans+=vis[i];
		cout<<ans<<" ";
	}
	cout<<endl;






 
	return 0;
}