#include<bits/stdc++.h>
#define maxn 5000
using namespace std;
int n,m,q;
bool tk[maxn][maxn];
long long contain(int x,int y) {
	long long u=1;
	long long b=1;
	int cx=x;
	int cy=y;
	while(!tk[cx-1][cy]) {
		u++;
		cx-=1;
		cy-=1;
		if(tk[cx][cy]) break;
		u++;
	}
	cx=x;
	cy=y;
	while(!tk[cx][cy+1]) {
		b++;
		cx+=1;
		cy+=1;
		if(tk[cx][cy]) break;
		b++;
	}
	//cout<<u<<" "<<b<<endl;
	long long ret=u*b;
	u=1;
	b=1;
	cx=x;
	cy=y;
	while(!tk[cx][cy-1]) {
		u++;
		cx-=1;
		cy-=1;
		if(tk[cx][cy]) break;
		u++;
	}
	cx=x;
	cy=y;
	while(!tk[cx+1][cy]) {
		b++;
		cx+=1;
		cy+=1;
		if(tk[cx][cy]) break;
		b++;
	}
	//cout<<u<<" "<<b<<endl;
	ret+=(u*b-1);
	return ret;
}
int main() {
	scanf("%d %d %d",&n,&m,&q);
	long long tot=0;
	for(int i=0;i<=n+3;i++) {
		for(int j=0;j<=m+3;j++) tk[i][j]=true;
	}
	for(int i=2;i<=n+1;i++) {
		for(int j=2;j<=m+1;j++) tk[i][j]=false;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			int k1=(m-j);
			int k2=(n-i);
			tot=tot+(1+4*min(k1,k2)+(k1>k2)+(k2>k1));
			//tot=tot+(1+k1+k2+2*min(k1,k2));
		}
	}
	while(q--) {
		int x,y;
		scanf("%d %d",&x,&y);
		x+=1;
		y+=1;
		long long c=contain(x,y);
		tk[x][y]=!tk[x][y];
		if(tk[x][y]) tot-=c;
		else tot+=c;
		printf("%lld\n",tot);
	}
	return 0;
}