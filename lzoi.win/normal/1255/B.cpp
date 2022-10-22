#include<cstdio>
const int N=1005;
int n,Minn1,Minn2,Num[N],Answer,T,m;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline void Init(){
	Minn1=Minn2=-1;
	Answer=0;
	n=Read();m=Read();
	for(register int i=1;i<=n;i++){
		Num[i]=Read();
		Answer+=Num[i]<<1;
		if(Minn1==-1||Num[i]<Num[Minn1]){
			Minn2=Minn1;
			Minn1=i;
		}
		else if(Minn2==-1||Num[i]<Num[Minn2]) Minn2=i;
	}
}
inline void Query(){
	if(m<n) return puts("-1"),void();
	if(n==2) return puts("-1"),void();
	int k=n-2<<1;
	if(m>=k){
		m-=k;
		Answer+=(n-4)*(Num[Minn1]+Num[Minn2]);
		for(register int i=1;i<=m;i++)
			Answer+=Num[Minn1]+Num[Minn2];
		printf("%d\n",Answer);
		for(register int i=1;i<=n;i++){
			if(i==Minn1||i==Minn2) continue ;
			printf("%d %d\n",i,Minn1);
			printf("%d %d\n",i,Minn2);
		}
		for(register int i=1;i<=m;i++)
			printf("%d %d\n",Minn1,Minn2);
	}
	else{
		m-=n;
		for(register int i=1;i<=m;i++)
			Answer+=Num[Minn1]+Num[Minn2];
		printf("%d\n",Answer);
		for(register int i=1;i<n;i++)
			printf("%d %d\n",i,i+1);
		printf("1 %d\n",n);
		for(register int i=1;i<=m;i++)
			printf("%d %d\n",Minn1,Minn2);
	}
}
int main(){
	for(T=Read();T;T--){
		Init();
		Query();
	}
	return 0;
}