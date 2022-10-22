#include<cstdio>
typedef long long ll;
int n;
int cnt[1<<20|1][2];
ll ans;
int main(){
	scanf("%d",&n);
	int rxor=0;
	cnt[0][0]=1;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[rxor^=a][i&1]++;
	}
	for(int i=0;i<=(1<<20);i++){
		ans+=1ll*cnt[i][0]*(cnt[i][0]-1)>>1;
//		printf("cnt[%d][%d]=%d\n",i,0,cnt[i][0]);
		ans+=1ll*cnt[i][1]*(cnt[i][1]-1)>>1;
//		printf("cnt[%d][%d]=%d\n",i,1,cnt[i][1]);
	}
	printf("%I64d\n",ans);
	return 0;
}