#include<cstdio>
const int N=40;
int n,a,i,cnt[N];
long long ans;
int Count(int x){
	int s=0;
	while(x)
	x-=x&-x,s++;
	return s;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		cnt[Count(a)]++;
	}
	for(i=0;i<N;i++)
		ans=ans+1ll*cnt[i]*(cnt[i]-1)/2;
	printf("%I64d",ans);
}