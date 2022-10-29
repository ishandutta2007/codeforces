#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,q;
int x[16];
int y[16];
int a[128];
int b[128];
int c[128];

ll dp[16][1<<12];

ll f(int k, int mask){
	//printf("%d %d\n",k,mask);
	if(dp[k+1][mask]<0){
		for(int i=0;i<q;++i){
			if(b[i]==k)swap(a[i],b[i]);
			if(a[i]==k&&(mask&(1<<b[i]))&&c[i]!=k){
				dp[k+1][mask]=0;
				return 0;
			}
		}
		ll r=0;
		if(!mask)r=1;
		else {
			int d=__builtin_ctz(mask);
			assert(mask&(1<<d));
			int m1=mask^(1<<d);
			int m2=m1;
			do {
				int m4=m1^m2;
				int m3=m2|(1<<d);assert((m3|m4)==mask);
				int s=-1;
				bool can=true;
				for(int i=0;i<m;++i){
					if(y[i]==k){
						swap(x[i],y[i]);
					}
					if(x[i]==k){
						if(m3&(1<<y[i])){
							if(s>=0&&s!=y[i])can=false;
							s=y[i];
						}
					}
					else {
						if(((m3&(1<<x[i]))&&(m4&(1<<y[i])))||((m3&(1<<y[i]))&&(m4&(1<<x[i]))))can=false;
					}
				}
				for(int i=0;i<q;++i){
					if(c[i]==k){
						if((m3&(1<<a[i]))&&(m3&(1<<b[i])))can=false;
					}
					else {
						if((m3&(1<<a[i]))&&(m4&(1<<b[i]))||((m3&(1<<b[i]))&&(m4&(1<<a[i]))))can=false;
					}
				}
				if(can){
					if(s>=0)r+=f(s,m3^(1<<s))*f(k,m4);
					else {
						for(int i=0;i<n-1;++i){
							if(m3&(1<<i)){
								r+=f(i,m3^(1<<i))*f(k,m4);
							}
						}
					}
				}
				m2=(m2-1)&m1;
			} while(m2!=m1);
		}
		dp[k+1][mask]=r;
	}
	return dp[k+1][mask];
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=0;i<m;++i)scanf("%d%d",x+i,y+i),x[i]-=2,y[i]-=2;
	for(int i=0;i<q;++i)scanf("%d%d%d",a+i,b+i,c+i),a[i]-=2,b[i]-=2,c[i]-=2;
	for(int i=0;i<q;++i)if(a[i]==b[i]&&a[i]!=c[i]){cout<<"0"<<endl;return 0;}
	memset(dp,-1,sizeof(dp));
	cout<<f(-1,(1<<(n-1))-1)<<endl;
	return 0;
}