#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
char it[2001][2001];
const llo mod=998244353 ;
llo aa[4001];
llo bb[4001];
vector<llo> adj[4001];
llo pre[2001*2001];
llo vis[4001];
vector<llo> ss;
void dfs(llo no){
	vis[no]=1;
	ss.pb(no);
	for(auto j:adj[no]){
		if(vis[j]==0){
			dfs(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	pre[0]=1;
	for(llo i=1;i<=2000*2000;i++){
		pre[i]=(pre[i-1]+pre[i-1]);
		if(pre[i]>=mod){
			pre[i]-=mod;
		}
	}
	llo n,m;
	cin>>n>>m;
	if(n%2==1 and m%2==0){
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				cin>>it[j][i];
			}
		}
		swap(n,m);
	}
	else{
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				cin>>it[i][j];
			}
		}
	}
	if(n%2==0 and m%2==0){
		llo ans=1;
		for(llo i=0;i<n;i++){
			for(llo j=0;j<m;j++){
				if(it[i][j]=='?'){
					ans=(ans*2)%mod;
				}
			}
		}
		cout<<ans<<endl;
		return 0;
	}
	if(n%2==0){
		llo ans=0;
		for(llo k=0;k<2;k++){
			llo cur=1;
			for(llo i=0;i<n;i++){
				llo su=0;
				llo su2=0;
				for(llo j=0;j<m;j++){
					if(it[i][j]=='?'){
						su2+=1;
					}
					else{
						su^=(it[i][j]-'0');
					}
				}
				if(su2==0 ){
					if(su!=k){
						cur=0;
					}
				}
				else{
					for(llo j=0;j<su2-1;j++){
						cur=(cur*2)%mod;
					}
				}
				
			}
			ans=(ans+cur)%mod;

		}
		cout<<ans<<endl;
		return 0;
	}

	for(llo i=0;i<n;i++){
		for(llo j=0;j<m;j++){
			if(it[i][j]=='?'){
				adj[i].pb(j+n);
				adj[j+n].pb(i);
			}
			else if(it[i][j]=='1'){
				aa[i]^=1;
				aa[n+j]^=1;
			}
		}
	}
	llo cur=1;
	llo cur2=1;
	for(llo i=0;i<n+m;i++){
		if(vis[i]==0){
			ss.clear();
			dfs(i);
			llo x=0;
			for(auto j:ss){
				x^=aa[j];
			}
			llo m=0;
			for(auto j:ss){
				m+=adj[j].size();
			}
			m/=2;
			llo xx=ss.size();
			if(xx%2==0){
				//xor=0 always
				if(x==1){
					cur=0;
					cur2=0;
				}
				else{
					cur=(cur*pre[m-(xx-1)])%mod;
					cur2=(cur2*pre[m-(xx-1)])%mod;
				}
			}
			else{

				if(x==0){
					cur=(cur*pre[m-(xx-1)])%mod;
				}
				else{
					cur=0;
				}
				if(x==1){
					cur2=(cur2*pre[m-(xx-1)])%mod;
				}
				else{
					cur2=0;
				}
			}

		}
	}
	cur=(cur+cur2)%mod;
	cout<<cur<<endl;






	return 0;
}