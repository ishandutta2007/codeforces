#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,M=18;
int n,k,m,S,a[N],p[N],pos[N],cnt[N],f[N][M];
int in(int x,int y){return (x&y)==x;}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>m,k-=2000,S=(1<<n)-1;
	while(m--){
		int x,y;cin>>x>>y;
		a[y]|=1ll<<(x-1);
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof f),f[0][0]=1;
		for(int s=0;s<=S;s++)
			for(int j=0;j<=n;j++){
				int t=__builtin_popcount(s)+1;
				if(pos[t]){
					if(in(a[pos[t]],s)&&!in(1ll<<(pos[t]-1),s))
						f[s|1ll<<(pos[t]-1)][pos[t]^i?j:t]+=f[s][j];
				}else for(int l=1;l<=n;l++)
					if(~s>>(l-1)&1&&in(a[l],s))
						f[s|1ll<<(l-1)][l^i?j:t]+=f[s][j];
			}
		int s=0;
		for(int j=1;j<=n;j++){
			if(!pos[j]&&s+f[S][j]>=k){
				p[i]=j,pos[j]=i,k-=s;
				break;
			}
			s+=f[S][j];
		}
		if(!p[i])
			cout<<"The times have changed\n",exit(0);
	}
	for(int i=1;i<=n;i++) 
		cout<<p[i]<<" ";
	cout<<"\n";
}