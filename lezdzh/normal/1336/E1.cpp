#include<cstdio>

using namespace std;

const int md=998244353;
long long b[41],a[41];
int f[41][41][50001];
int ans[41];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		long long o;
		scanf("%lld",&o);
		for(int j=m-1;j>=0;j--)
			if(o>>j&1){
				if(b[j]!=0)o^=b[j];
				else{
					b[j]=o;
					break;
				}
			}
	}
	int z=0;
	for(int i=m-1;i>=0;i--)
		if(b[i]!=0)z++;
	int aa=1;
	for(int i=1;i<=n-z;i++)
		aa=aa*2%md;
	if(z<=20){
		for(int i=m-1;i>=0;i--)
			if(b[i])a[++a[0]]=b[i];
		for(int s=0;s<1<<z;s++){
			long long o=0;
			for(int i=0;i<z;i++)
				if(s>>i&1)o^=a[i+1];
			int w=0;
			for(int i=0;i<m;i++)
				if(o>>i&1)w++;
			ans[w]=(ans[w]+aa)%md;
		}
	}
	else{
		int mm=0;
		for(int i=0;i<m;i++)
			if(b[i]){
				a[++a[0]]=0;
				for(int j=i-1;j>=0;j--)
					if(b[j]&&b[i]>>j&1)
						b[i]^=b[j];
				for(int j=i-1;j>=0;j--)
					if(!b[j])a[a[0]]=a[a[0]]*2+(b[i]>>j&1);
			}
			else mm++;
		f[0][0][0]=1;
		for(int i=0;i<a[0];i++)
			for(int j=0;j<=i;j++)
				for(int s=0;s<1<<mm;s++){
					//printf("%d %d %d %d\n",i,j,s,f[i][j][s]);
					(f[i+1][j+1][s^a[i+1]]+=f[i][j][s])%=md;
					(f[i+1][j][s]+=f[i][j][s])%=md;
				}
		for(int j=0;j<=a[0];j++)
			for(int s=0;s<1<<mm;s++){
				int w=0;
				for(int i=0;i<mm;i++)
					if(s>>i&1)w++;
				ans[w+j]=(ans[w+j]+1ll*aa*f[a[0]][j][s])%md;
			}
	}
	for(int i=0;i<=m;i++)
		printf("%d%c",ans[i],i==m?'\n':' ');
}