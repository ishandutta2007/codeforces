#include<cstdio>
const int N=6000002;
int n,m,a,i,j,k,t[N][2],s[N],cnt=1,f[N];
void push(int a){
	for(j=19,i=1;j>=0;j--){
		if(!t[i][a>>j&1])
			t[i][a>>j&1]=++cnt;
		i=t[i][a>>j&1];
		s[i]++;
	}
}
int Query(int k){
	a=0;
	for(j=19,i=1;j>=0;j--){
		if(s[t[i][k>>j&1]]<(1<<j))
			i=t[i][k>>j&1];
		else
			a|=1<<j,i=t[i][k>>j&1^1];
		if(!i)
			break;
	}
	return a;
}
int main(){
	scanf("%d%d",&n,&m);
	while(n--){
		scanf("%d",&a);
		if(!f[a])
		push(a);
		f[a]=1;
	}
	while(m--){
		scanf("%d",&a);
		k^=a;
		printf("%d\n",Query(k));
	}
	return 0;
}