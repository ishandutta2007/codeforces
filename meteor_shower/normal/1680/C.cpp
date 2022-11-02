#include<cstdio>
#include<cstring>
const int N=2e5+5;
int sum0[N],sum1[N];
char s[N];
int n;
inline int Get0(const int ll,const int rr){
	return sum0[rr]-sum0[ll-1];
}
inline int Get1(const int ll,const int rr){
	return sum1[rr]-sum1[ll-1];
}
inline void Init(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		sum0[i]=sum0[i-1];
		sum1[i]=sum1[i-1];
		if(s[i]=='0') sum0[i]++;
		else sum1[i]++;
	}
	return ;
}
inline bool Check(const int mid){
	int j=1;
	for(int i=1;i<=n;i++){
		if(j<i) j=i;
		while(j<n&&Get0(i,j+1)<=mid) j++;
		if(Get0(i,j)>mid) continue ;
		if(Get1(1,i-1)+Get1(j+1,n)<=mid) return 1;
	}
	return 0;
}
inline void Solve(){
	int ll=0,rr=n;
	while(ll<rr){
		int mid=ll+rr>>1;
		if(Check(mid)) rr=mid;
		else ll=mid+1;
	}
	if(ll>sum1[n]) ll=sum1[n];
	printf("%d\n",ll);
	return ;
}
int T;
int main(){
	for(scanf("%d",&T);T;T--){
		Init();
		Solve();
	}
	return 0;
}