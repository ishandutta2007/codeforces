#include<cstdio>
typedef long long ll;
const int MAXN=2e5+5;
int n;
ll f[MAXN][2];
ll ans1,ans2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		if(a>0){
			f[i][0]=f[i-1][0];
			f[i][1]=f[i-1][1]+1;
		}
		else{
			f[i][0]=f[i-1][1]+1;
			f[i][1]=f[i-1][0];
		}
		ans1+=f[i][0];
		ans2+=f[i][1];
	}
	printf("%I64d %I64d\n",ans1,ans2);
	return 0;
}