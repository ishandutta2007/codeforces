#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
int n,s,d[N],p[N],vis[N];
void Solve(){
	cin>>n>>s;
	for(int i=1;i<=n;++i)d[i]=vis[i]=0;
	for(int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		++d[u],++d[v];
	}
	bool ok=1;
	for(int i=1;i<=n;++i){
		int x;
		cin>>x;
		p[x]=i;
		if(x!=i){ok=0;}
	}
	if(ok){
		cout<<"Alice\n";
		return;
	}
	int rt=-1;
	for(int i=1;i<=n;++i){
		if(d[i]==n-1){
			rt=i;
			break;
		}
	}
	if(rt==-1){
		cout<<"Alice\n";
		return;
	}
	if(s!=rt){
		if(p[rt]!=rt){
			if(p[s]==rt){
				cout<<"Bob\n";
				return;
			}
			for(int i=1;i<=n;++i){
				if(p[i]==rt){
					swap(p[i],p[rt]);
					break;
				}
			}
		}
		else{
			if(n==3){
				cout<<(p[1]==1&&p[2]==2&&p[3]==3?"Alice\n":"Bob\n");
				return;
			}
			bool ok=0;
			for(int i=1;i<=n;++i){
				if(p[i]==i)continue;
				if(p[p[i]]==i&&i!=s&&p[i]!=s){
					swap(p[i],p[p[i]]);
					ok=1;
					break;
				}
			}
			if(!ok){
				for(int i=1;i<=n&&!ok;++i){
					for(int j=i+1;j<=n;++j){
						if(i!=s&&j!=s&&i!=rt&&j!=rt){
							ok=1;
							swap(p[i],p[j]);
							break;
						}
					}
				}
			}
		}
		s=rt;
	}
	if(p[rt]!=rt){
		cout<<"Bob\n";
		return;
	}
	int cir=0;
	for(int i=1;i<=n;++i){
		if(vis[i])continue;
		for(int u=i;!vis[u];u=p[u]){
			vis[u]=1;
		}
		++cir;
	}
	cout<<((n==cir||(n-cir)&1)?"Alice\n":"Bob\n");
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}
//qwq