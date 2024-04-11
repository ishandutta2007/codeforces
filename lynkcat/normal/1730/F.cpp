#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,a[5005],w[5005],res,ans,f[5005][305],msk,sb,p[66],v[11];

void fuck(int x,int y,int z){
	int i,j,k,t,sb,i1,i2,it=0,ii,jj;
	for(i=1;i<=min(m,n-x);i++){
		if(!(y&b(i)))continue;
		v[++it]=i;
	}
	for(t=y;;t=((t-1)&y)){
		sb=z;
		i1=i2=0;
		for(ii=1;ii<=it;ii++){
			i=v[ii];
			if(!(t&b(i)))sb+=((w[x]>w[x+i])?1:-1);
			for(jj=ii+1;jj<=it;jj++){
				j=v[jj];
				if((t&b(i))&&!(t&b(j)))sb+=((w[x+i]>w[x+j])?1:-1);
				if(!(t&b(i))&&!(t&b(j)))sb+=(w[x+i]>w[x+j]);
			}
		}
		f[x+1][t]=max(f[x+1][t],sb);
		if(!t)break;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin>>n>>m;
	msk=b(m+1)-1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		w[a[i]]=i;
	}
	for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)ans+=(w[i]>w[j]);
	memset(f,-10,sizeof(f));
	f[1][msk]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=msk;j++){
			if(!(j&1)){
				f[i+1][j/2+b(m)]=max(f[i+1][j/2+b(m)],f[i][j]);continue;
			}
			fuck(i,j/2+b(m),f[i][j]);
		}
	}
	for(i=0;i<=msk;i++)res=max(res,f[n][i]);
	cout<<ans-res;
}