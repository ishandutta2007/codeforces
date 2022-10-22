#include<cstdio>
#include<cstring>
const int N=5e4+5;
int Pre[N],T;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline void Pre_Init(){
	for(register int i=1;i<N;i++)
		Pre[i]=Pre[i-1]+i;
}
inline int Abs(const int x){
	return x>0?x:-x;
}
inline void Query(){
	int a=Read();
	int b=Read();
	if(a==b) return puts("0"),void();
	int p=Abs(a-b);
	int k;
	for(k=1;Pre[k]<p;k++);
	for(;Pre[k]-p&1;k++);
	printf("%d\n",k);
}
int main(){
	Pre_Init();
	for(T=Read();T;T--)
		Query();
	return 0;
}