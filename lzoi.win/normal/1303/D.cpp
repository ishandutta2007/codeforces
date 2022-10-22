#include<cstdio>
typedef long long ll;
const int MAXN=1e5+5;
int n;
ll m;
int cnt[40];
int ff(int x){
	int res=0;
	while(x>1) res++,x>>=1;
	return res;
}
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%I64d%d",&m,&n);
		for(int i=0; i<=30; i++)
			cnt[i]=0;
		ll sum=0;
		for(int i=1; i<=n; i++){
			int x; scanf("%d",&x);
			cnt[ff(x)]++;
			sum+=x;
		}
		if(m>sum){
			puts("-1");
			continue;
		}
		sum=0;
		int ans=0;
		for(int i=0; i<=30; i++){
			if((1<<i)&m) sum--;
			if(sum<0){
				int k;
				for(k=i;!cnt[k];k++)
					cnt[k]=1;
				cnt[k]--;
				ans+=k-i;
				sum=0;
			}
			sum+=cnt[i];
			sum>>=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}