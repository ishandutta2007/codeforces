#include<cstdio>
#include<cstring>
const int N=15;
const int Inf=1e4+5;
int n,T,Num[N];
bool Vis[Inf],Cha[N];
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline void Work(const int x){
	for(register int i=0;i<=9;i++){
		int p=Num[x]%10000/1000;
		if(!Vis[Num[x]-p*1000+i*1000]){
			Num[x]=Num[x]-p*1000+i*1000;
			Vis[Num[x]]=1;
			return ;
		}
	}
}
inline void Query(){
	memset(Vis,0,sizeof(Vis));
	memset(Cha,0,sizeof(Cha));
	int ss=0;
	for(register int i=1;i<=n;i++){
		Num[i]=Read();
		if(Vis[Num[i]]) Cha[i]=1,ss++;
		Vis[Num[i]]=1;
	}
	printf("%d\n",ss);
	for(register int i=1;i<=n;i++){
		if(Cha[i])
			Work(i);
		if(Num[i]>=1000) printf("%d\n",Num[i]);
		else if(Num[i]>=100) printf("0%d\n",Num[i]);
		else if(Num[i]>=10) printf("00%d\n",Num[i]);
		else printf("000%d\n",Num[i]);
	}
}
int main(){
	for(T=Read();T;T--){
		n=Read();
		Query();
	}
	return 0;
}