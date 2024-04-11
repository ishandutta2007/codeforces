#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef   long long int llo;
#define mp make_pair
#define pb push_back
#define a first
#define b second
llo dist2[200001];
llo dist[200001];
llo sp[200001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n,m,k;
	cin>>n>>m>>k;
	memset(sp,0,sizeof(sp));
	llo it[k];
	for(llo i=0;i<k;i++){
		cin>>it[i];
		sp[it[i]-1]=1;
		it[i]--;
	}
	llo x,y;
	vector<llo> adj[n];
	for(llo i=0;i<m;i++){
		cin>>x>>y;
		adj[x-1].pb(y-1);
		adj[y-1].pb(x-1);
	}
	for(llo i=0;i<n;i++){
		dist[i]=-1;

	}
	dist[0]=0;
	for(llo i=0;i<n;i++){
		dist2[i]=-1;
	}
	dist2[n-1]=0;
	priority_queue<pair<llo,llo>> heap;
	heap.push(mp(0,0));

	llo vis[n];
	vis[0]=0;

	while(heap.size()>0){
		pair<llo,llo> no=heap.top();
		heap.pop();
		no.a=-no.a;
		for(llo j=0;j<adj[no.b].size();j++){
			llo nn=adj[no.b][j];
			if(dist[nn]>no.a+1 or dist[nn]==-1){
				dist[nn]=no.a+1;
				vis[nn]=no.b;
				heap.push(mp(-dist[nn],nn));
			}
		}
	}
	heap.empty();
	heap.push(mp(0,n-1));
	while(heap.size()>0){
		pair<llo,llo> no=heap.top();
		heap.pop();
		no.a=-no.a;
		for(llo j=0;j<adj[no.b].size();j++){
			llo nn=adj[no.b][j];
			if(dist2[nn]>no.a+1 or dist2[nn]==-1){
				dist2[nn]=no.a+1;
				heap.push(mp(-dist2[nn],nn));
			}
		}
	}

	

	llo ans=dist[n-1];
	llo ma=0;
	vector<pair<llo,llo>> ac;
	for(llo i=0;i<n;i++){
		if(sp[i]){
		ac.pb(mp(dist[i]-dist2[i],i));
		}
	}
	sort(ac.begin(),ac.end());
	llo maa=dist[ac[0].b];
	for(llo i=1;i<k;i++){
		ma=max(ma,maa+dist2[ac[i].b]+1);
		maa=max(maa,dist[ac[i].b]);
	}

	
	//cout<<endl;
	//cout<<ans<<endl;
	cout<<min(ma,ans)<<endl;


/*


	llo ma=0;
	llo ma2=0;
	llo ind=0;
	for(llo i=0;i<k;i++){
		if(dist[it[i]]<ma and dist[it[i]]>ma2){
			ma2=dist[it[i]];
		}
		if(dist[it[i]]>=ma){
			ma2=ma;
			ma=dist[it[i]];
			ind=it[i];

		}
	}
	llo ma3=0;
	llo ma4=0;
	llo ind2=0;
	for(llo i=0;i<k;i++){
		if(dist2[it[i]]<ma3 and dist2[it[i]]>ma4){
			ma4=dist2[it[i]];
		}
		if(dist2[it[i]]>=ma){
			ma4=ma;
			ma3=dist[it[i]];
			ind2=it[i];
		}
	}
	if(ind>ind2 or ind2>ind){
		ans=min(ans,ma+ma3+1);
	}*/


	









	return 0;
}