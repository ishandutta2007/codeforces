#include<cstdio>
int n;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline int Gcd(const int x,const int y){
	return x%y?Gcd(y,x%y):y;
}
inline void Query(){
	int x=Read(),y=Read();
	int k=Gcd(x,y);
	if(k!=1) puts("Infinite");
	else puts("Finite");
}
int main(){
	for(n=Read();n;n--)
		Query();
	return 0;
}