//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<pair<llo,llo>> aa;
vector<llo> cc;

llo m,k;	
llo val[1001][1001];
llo vis[1001];
bool check(llo mid){
	llo coo=0;
	for(llo i=0;i<mid;i++){
		for(llo j=0;j<mid;j++){
			if(vis[i]==1 and vis[j]==1){
				val[i][j]=0;
			}
			else{
				coo++;
				val[i][j]=0;
			}
		}
	}
	if(coo<m){
		return false;
	}
	queue<llo> dd;
	for(auto j:cc){
		dd.push(j);
	}
	
	llo co=0;
	llo co2=0;
	for(llo i=0;i<mid;i++){
		for(llo j=0;j<mid;j++){
			if(vis[i]==0 and vis[j]==1){
				co++;

			}
			else if(vis[i]==1 and vis[j]==0){
				co2++;
			}
		}
	}
	if(co>=co2){
		for(llo i=0;i<mid;i++){
			for(llo j=0;j<mid;j++){
				if(vis[i]==0 and vis[j]==1){
					if(dd.size()){
						val[i][j]=dd.front();
						dd.pop();
					}
				}
				else if(vis[i]==1 and vis[j]==0){
				}
			}
		}
		for(llo i=0;i<mid;i++){
			for(llo j=0;j<mid;j++){
				if(vis[i]==0 and vis[j]==0){
					if(dd.size()){
						val[i][j]=dd.front();
						dd.pop();
					}
				}
			}
		}
		for(llo i=0;i<mid;i++){
			for(llo j=0;j<mid;j++){
				if(vis[i]==0 and vis[j]==1){
					
				}
				else if(vis[i]==1 and vis[j]==0){
					if(dd.size()){
						val[i][j]=dd.front();
						dd.pop();
					}
				}
			}
		}
	}
	else{
		for(llo i=0;i<mid;i++){
			for(llo j=0;j<mid;j++){
				if(vis[i]==0 and vis[j]==1){
					
				}
				else if(vis[i]==1 and vis[j]==0){
					if(dd.size()){
						val[i][j]=dd.front();
						dd.pop();
					}
				}
			}
		}
		for(llo i=0;i<mid;i++){
			for(llo j=0;j<mid;j++){
				if(vis[i]==0 and vis[j]==0){
					if(dd.size()){
						val[i][j]=dd.front();
						dd.pop();
					}
				}
			}
		}
		for(llo i=0;i<mid;i++){
			for(llo j=0;j<mid;j++){
				if(vis[i]%2==0 and vis[j]==1){
					if(dd.size()){
						val[i][j]=dd.front();
						dd.pop();
					}
				}
				else if(vis[i]==1 and vis[j]==0){
				}
			}
		}
	}
	for(llo i=0;i<mid;i++){
		for(llo j=0;j<mid;j++){
			if(i<mid-1 and j<mid-1){
				if(val[i][j]>0 and val[i][j]==val[i+1][j+1]){
					return false;
				}
			}
			if(i>0 and j<mid-1){
				if(val[i][j]>0 and val[i][j]==val[i-1][j+1]){
					return false;
				}
			}
		}
	}
	return true;


}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	for(llo i=1;i<=1000;i+=2){
		vis[i]=1;
	}
	while(t--){
		
		cin>>m>>k;
		aa.clear();
		cc.clear();
		
		for(llo i=0;i<k;i++){
			llo bb;
			cin>>bb;
			aa.pb({bb,i+1});
		}
		sort(aa.begin(),aa.end());
		reverse(aa.begin(),aa.end());
		for(auto j:aa){
			for(llo i=0;i<j.a;i++){
				cc.pb(j.b);
			}
		}
		llo high=sqrt(2*m)+2;
		for(llo i=19;i>=0;i--){
			if(high-(1<<i)>0){
				if(check(high-(1<<i))){
					high-=(1<<i);
				}
			}
		}
		check(high);
		cout<<high<<endl;
		for(llo i=0;i<high;i++){
			for(llo j=0;j<high;j++){
				cout<<val[i][j]<<" ";
			}
			cout<<endl;
		}


	}








	return 0;
}