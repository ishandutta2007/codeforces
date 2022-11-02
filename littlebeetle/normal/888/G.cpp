#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002,K=31;
typedef long long ll;
int n,a[N],i,j,k,cnt=1;
int L[N*K],R[N*K],ldfn[N*K],rdfn[N*K];
ll ans;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
void Insert(int x,int k){
	for(i=1,j=30;j>=0;j--){
		if(x>>j&1){
			if(!R[i]){
				R[i]=++cnt;
				ldfn[cnt]=1<<30;
			}
			i=R[i];
			ldfn[i]=min(ldfn[i],k);
			rdfn[i]=max(rdfn[i],k);
		}
		else{
			if(!L[i]){
				L[i]=++cnt;
				ldfn[cnt]=1<<30;
			}
			i=L[i];
			ldfn[i]=min(ldfn[i],k);
			rdfn[i]=max(rdfn[i],k);
		}
	}
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(k=1;k<=n;k++)
		Insert(a[k],k);
}
int Get(int rt,int dep,int val){
	if(dep==-1)return a[ldfn[rt]]^val;
	if(val>>dep&1){
		if(R[rt])
			return Get(R[rt],dep-1,val);
		else	
			return Get(L[rt],dep-1,val);
	}
	else{
		if(L[rt])
			return Get(L[rt],dep-1,val);
		else	
			return Get(R[rt],dep-1,val);
		}
}
void dfs(int i,int dep){
	if(L[i])dfs(L[i],dep-1);
	if(R[i])dfs(R[i],dep-1);
	if(L[i]&&R[i]){
		int sum=1<<30;
		for(int j=ldfn[L[i]];j<=rdfn[L[i]];j++)
			sum=min(sum,Get(R[i],dep-1,a[j]));
		ans+=sum;
	}
}
void work(){
	dfs(1,30);
	printf("%lld",ans);
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}