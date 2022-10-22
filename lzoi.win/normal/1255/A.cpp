#include<cstdio>
int T;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline int Abs(const int x){
	return x>0?x:-x;
}
inline void Get(int&ss,int&p,const int Val){
	int q=p/Val;
	ss+=q;
	p-=q*Val;
}
inline int Query(){
	int ss=0;
	int a=Read(),b=Read();
	int p=Abs(a-b);
	Get(ss,p,5);
	Get(ss,p,2);
	Get(ss,p,1);
	return ss;
}
int main(){
	for(T=Read();T;T--)
		printf("%d\n",Query());
	return 0;
}