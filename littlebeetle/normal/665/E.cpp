#include<cstdio>
const int N=1000002,K=31;
int n,k,a,i,s[N];
int ch[N*K][2],sz[N*K],cnt=1;
long long Ans;
void init(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[i]=s[i-1]^a;
	}
}
void Insert(int x){
	int i,j;
	for(i=1,j=30;j>=0;j--){
		if(!ch[i][x>>j&1])
			ch[i][x>>j&1]=++cnt;
		i=ch[i][x>>j&1];
		sz[i]++;
	}
}
void Query(int x){
	int i,j,s=0;
	for(i=1,j=30;j>=0;j--){
		if(s+(1<<j)>=k)
			Ans+=sz[ch[i][x>>j&1^1]],
			i=ch[i][x>>j&1];
		else
			s+=1<<j,
			i=ch[i][x>>j&1^1];
	}
}
void work(){
	Insert(s[0]);
	for(i=1;i<=n;i++){
		Query(s[i]);
		Insert(s[i]);
	}
	printf("%lld",Ans);
	//while(1);
}
int main(){
	init();
	work();
	return 0;
}