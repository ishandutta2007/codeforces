#include<cstdio>

using namespace std;

int n,z,q,a[100001];
int b[500][100001];
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int z=1;while(z*z<n)z++;
	for(int i=1;i<z;i++)for(int j=n;j;j--)
		b[i][j]=j+a[j]+i>n?1:b[i][j+a[j]+i]+1;
	scanf("%d",&q);while(q--){
		int p,k,s=0;scanf("%d%d",&p,&k);
		if(1ll*k*k<n)printf("%d\n",b[k][p]);
		else{while(p<=n)p+=a[p]+k,s++;printf("%d\n",s);}
	}
}