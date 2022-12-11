#include<cstdio>
#include<algorithm>
using namespace std;

const int md=1000000007;
int f[101][10001];
int a[101],b[101],x[100001],ans[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=n;i++){
		scanf("%d",&b[i]);
		b[i]+=b[i-1];
	}
	for(int i=2;i<=n;i++)
		b[i]+=b[i-1];
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d",&x[i]);
	int mn=2e9,mx=2e9;
	for(int i=1,z=0;i<=n;i++){
		mn=min(mn,-b[i]/i);
		z+=a[i];
		mx=min(mx,(z-b[i])/i+1);
	}
	mn--;
	f[0][0]=1;
	for(int j=1;j<=10000;j++)
		f[0][j]=(f[0][j]+f[0][j-1])%md;
	for(int o=mn;o<=mx;o++){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=10000;j++){
				if(j-b[i]>=i*o){
					int k=min(a[i],j);
					f[i][j]=(f[i-1][j]-(j-k-1==-1?0:f[i-1][j-k-1])+md)%md;
				}
				else f[i][j]=0;
			}
			for(int j=1;j<=10000;j++)
				f[i][j]=(f[i][j]+f[i][j-1])%md;
		}
		ans[o-mn]=f[n][10000];
	}
	for(int i=1;i<=q;i++){
		x[i]=max(x[i],mn);
		x[i]=min(x[i],mx);
		printf("%d\n",ans[x[i]-mn]);
	}
}