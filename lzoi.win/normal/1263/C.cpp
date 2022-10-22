#include<cstdio>
#include<cmath>
const int N=1e7+5;
int Prime[N],cnt_prime;
bool Vis[N],flag;
int Answer[N],cnt_ans;
int n,T,p;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline void Init(){
	for(register int i=2;i<=N-5;i++){
		if(!Vis[i])	Prime[++cnt_prime]=i;
		for(register int j=1;j<=cnt_prime&&i*Prime[j]<=n;j++){
			Vis[i*Prime[j]]=1;
			if(i%Prime[j]==0) break ;
		}
	}
}
inline void Query(){
	n=Read();
	int p=-1;
	flag=0;
//	printf("%d\n",n);
	Answer[cnt_ans=1]=n;
//	cnt_ans=0;
	for(register int i=1;i<=cnt_prime;i++){
//		printf("%d %d\n",Prime[i],floor(n/Prime[i]));
		if(Prime[i-1]>n) break ;
		if(n/Prime[i]==p){
			flag=1;
			break ;
		}
		Answer[++cnt_ans]=n/Prime[i];
		p=n/Prime[i];
	}
	if(!flag)
		printf("%d\n",cnt_ans);
	else printf("%d\n",cnt_ans+p);
	if(flag) for(register int i=0;i<p;i++)
		printf("%d ",i);
	for(register int i=cnt_ans;i;i--)
		printf("%d ",Answer[i]);
	putchar('\n');
}
int main(){
	Init();
	for(T=Read();T;T--)
		Query();
	return 0;
}