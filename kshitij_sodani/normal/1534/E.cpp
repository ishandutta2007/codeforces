#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
typedef long long llo;

llo n,k;
vector<pair<llo,llo>> adj[502];
llo dist[502];
pair<llo,llo> ba[502];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	for(llo i=0;i<=n;i++){
		for(llo j=0;j<=k;j++){
			if(j<=i and k-j<=n-i){
				adj[i].pb({i-j+(k-j),j});
			}
		}

	}
	for(llo i=0;i<=n;i++){
		dist[i]=-1;
	}
	dist[0]=0;
	queue<llo> ss;
	ss.push(0);
	ba[0]={-1,-1};
	while(ss.size()){
		llo no=ss.front();
		ss.pop();
		for(auto j:adj[no]){
			if(dist[j.a]==-1){
				//cout<<no<<":"<<j.a<<endl;
				dist[j.a]=dist[no]+1;
				ba[j.a]={no,j.b};
				ss.push(j.a);
			}
		}
	}
	llo cur=n;
	vector<llo> aa;
	vector<llo> bb;
	for(llo i=0;i<n;i++){
		bb.pb(i+1);
	}
	if(dist[n]==-1){
		cout<<"-1"<<endl;
		return 0;
	}
	/*for(int i=0;i<n;i++){

	}*/
	llo ans=0;
	while(cur!=0){
		cout<<"? ";
		llo xx=ba[cur].b;
		vector<llo> cc;
		vector<llo> dd;
		for(llo j=0;j<xx;j++){
			cout<<aa.back()<<" ";
			cc.pb(aa.back());
			aa.pop_back();
		}
		for(llo j=0;j<k-xx;j++){
			cout<<bb.back()<<" ";
			dd.pb(bb.back());
			bb.pop_back();
		}
		for(auto j:cc){
			bb.pb(j);
		}
		for(auto j:dd){
			aa.pb(j);
		}
		cout<<endl;
		cin>>xx;
		ans=(ans^xx);
		cur=ba[cur].a;
	}

	cout<<"! "<<ans<<endl;




	return 0;
}