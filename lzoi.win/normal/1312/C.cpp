#include<cstdio>
typedef long long ll;
int n,k;
ll a;
int cnt[70];
bool ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=0; i<70; i++)
			cnt[i]=0;
		for(int i=1; i<=n; i++){
			scanf("%I64d",&a);
			for(int j=0;j<70;j++){
				cnt[j]+=a%k;
				a/=k;
			}
		}
		ans=1;
		for(int i=0; i<70; i++)
			if(cnt[i]>1) ans=0;
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;;
}