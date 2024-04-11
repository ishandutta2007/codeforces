#include<cstdio>
const int N=1000020;
int n,k,i,tmp,L[N],R[N];
char s[N];
void init(){
	scanf("%d%d%s",&n,&k,s+1);
}
int min(int x,int y){
	return x<y?x:y;
}
void work(){
	for(i=1;i<=n;i++)
		s[n+i]=s[n*2+i]=s[i];
	for(i=1;i<=n;i++)	
		if(s[i]==s[i+1])
			tmp=1;
	if(tmp==0){
		for(i=1;i<=n;i++)
			if(k%2==0)
				printf("%c",s[i]);
			else
				printf("%c",s[i+1]);
		return;
	}
	k=min(k,n);
	for(i=1;i<=n*3;i++)
		L[i]=1<<30,R[i]=1<<30;
	for(i=1;i<n*3;i++)
		if(s[i]==s[i+1])
			L[i]=L[i+1]=R[i]=R[i+1]=0;
	for(i=2;i<=n*3;i++)
		L[i]=min(L[i],L[i-1]+1);
	for(i=n*3-1;i;i--)
		R[i]=min(R[i],R[i+1]+1);
	for(i=2;i<=n*3;i++)
		if(L[i]&&L[i]<=R[i]){
			if(L[i]<=k)
				s[i]=s[i-1];
		}
	for(i=n*3-1;i;i--)
		if(R[i]&&R[i]<L[i]){
			if(R[i]<=k)
				s[i]=s[i+1];
		}
	for(i=n+1;i<=n*2;i++)
		if(L[i]<=k||R[i]<=k)
			printf("%c",s[i]);
		else{
			if(k%2==0)
				printf("%c",s[i]);
			else
				if(s[i]=='W')
					printf("B");
				else
					printf("W");
		}
		
	
}
int main(){
	init();
	work();
	return 0;
}