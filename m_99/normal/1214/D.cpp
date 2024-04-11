#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	
	vector<string> V(n);
	for(int i=0;i<n;i++)cin>>V[i];
	
	vector<int> dis1(n*m,Inf),dis2(n*m,Inf);
	
	queue<int> Q;
	Q.push(0);
	dis1[0] = 0;
	while(Q.size()!=0){
		int now = Q.front();
		Q.pop();
		
		int y = now/m;
		int x = now%m;
		if(y+1!=n){
			if(dis1[(y+1)*m+x]==Inf){
				if(V[y+1][x]=='.'){
					int to = (y+1)*m+x;
					dis1[to] = dis1[now]+1;
					Q.push(to);
				}
			}
			
		}
		if(x+1!=m){
			if(dis1[y*m+(x+1)]==Inf){
				if(V[y][x+1]=='.'){
					int to = y*m+(x+1);
					dis1[to] = dis1[now]+1;
					Q.push(to);
				}
			}
		}
	}
	Q.push(n*m-1);
	dis2[n*m-1]=0;
	while(Q.size()!=0){

		int now = Q.front();
		Q.pop();
		
		int y = now/m;
		int x = now%m;
		if(y-1!=-1){
			if(dis2[(y-1)*m+x]==Inf){
				if(V[y-1][x]=='.'){
					int to = (y-1)*m+x;
					dis2[to] = dis2[now]+1;
					Q.push(to);
				}
			}
			
		}
		if(x-1!=-1){
			if(dis2[y*m+(x-1)]==Inf){
				if(V[y][x-1]=='.'){
					int to = y*m+(x-1);
					dis2[to] = dis2[now]+1;
					Q.push(to);
				}
			}
		}
	}
	
	vector<int> cnt(n+m+1,0);
	
	for(int i=0;i<n*m;i++){
		if(dis1[i]==Inf||dis2[i]==Inf)continue;
		cnt[dis1[i]]++;
	}
	
	int ans = Inf;
	for(int i=1;i<=n+m-3;i++){
		ans = min(ans,cnt[i]);
	}
	
	cout<<ans<<endl;
		
	
	
	return 0;
}