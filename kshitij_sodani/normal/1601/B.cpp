//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
int aa[310000];
int bb[310000];
int dist[310000*2];
int ba[310000*2];
vector<int> adj[310000*2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>aa[i+1];
	}
	for(int i=0;i<n;i++){
		cin>>bb[i+1];
	}
	for(int i=0;i<=2*n+1;i++){
		dist[i]=-1;
	}
	for(int i=0;i<=n;i++){
		bb[0]=0;
		adj[i*2].pb((i+bb[i])*2+1);
	}

	//from 2*i+1 you can go to 2*(i-x) for 0<=x<=ai
	set<int> cur;
	for(int i=0;i<=n;i++){
		cur.insert(i);
	}
	dist[2*n]=0;
	queue<int> ss;
	ss.push(2*n);
	while(ss.size()){
		int no=ss.front();
		ss.pop();
		if(no%2==1){
			auto j=cur.lower_bound((no/2)-aa[no/2]);
			//go till no
			vector<int> qq;
			while(j!=cur.end()){
				if(*j>(no/2)){
					break;
				}
				int x=(*j)*2;
				if(dist[x]==-1){
					dist[x]=dist[no]+1;
					ba[x]=no;
					ss.push(x);
					qq.pb(*j);
				}

				j++;
			}
			for(auto j:qq){
				cur.erase(j);
			}
		}
		else{
			for(auto j:adj[no]){
				if(dist[j]==-1){
					//cout<<no<<":"<<j<<endl;
					dist[j]=dist[no]+1;
					ba[j]=no;
					ss.push(j);
				}
			}
		}
	}
	
/*	for(int i=0;i<=n;i++){
		cout<<dist[i*2]<<":"<<dist[i*2+1]<<endl;
	}*/
 	if(dist[1]==-1){
 		cout<<-1<<endl;
 		return 0;
 	}
 	cout<<((dist[1]-1)/2)<<endl;//<<","<<endl;
 	vector<int> ans;
 	int cur2=1;
 	while(true){
 		//cout<<cur2<<":";
 		if(cur2==2*n+1 or cur2==2*n){
 			break;
 		}
 		if(cur2%2==0){
 			ans.pb(cur2/2);
 		}
 		
 		cur2=ba[cur2];
 	}
 	//cout<<endl;
 	reverse(ans.begin(),ans.end());
 	for(auto j:ans){
 		cout<<j<<" ";
 	}
 	cout<<endl;

 

 
	return 0;
}