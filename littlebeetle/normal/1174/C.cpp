#include<cstdio>
const int N=100002;
int n,f[N],cnt,i,j;
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;i++){
		if(!f[i]){
			f[i]=++cnt;
			for(j=i;j<=n;j+=i)
			if(!f[j])
				f[j]=cnt;
		}
		printf("%d ",f[i]);
	}
}