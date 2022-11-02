#include<cstdio>
const int N=1002;
int T,n,cnt,a,b,c,i;
char s[N],t[N];
void init(){
	cnt=0;
	scanf("%d%d%d%d%s",&n,&a,&b,&c,s+1);
}
void work(){
	for(i=1;i<=n;i++){
		t[i]=0;
		if(s[i]=='R'&&b)
			t[i]='P',b--,cnt++;
		if(s[i]=='P'&&c)
			t[i]='S',c--,cnt++;
		if(s[i]=='S'&&a)
			t[i]='R',a--,cnt++;
	}
	t[n+1]=0;
	for(i=1;i<=n;i++){
		if(t[i]==0&&a)
			t[i]='R',a--;
		if(t[i]==0&&b)
			t[i]='P',b--;
		if(t[i]==0&&c)
			t[i]='S',c--;	
	}
	if(cnt>=(n+1)/2)
		printf("YES\n%s\n",t+1);
	else
		printf("NO\n");
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	//while(1);
}