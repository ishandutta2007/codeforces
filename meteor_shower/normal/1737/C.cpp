#include<cstdio>
const int N=1e5+5;
int r1,c1,r2,c2,r3,c3;
int midr,midc;
int n,xx,yy;
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(int x,char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline bool Check(int ra,int ca,int rb,int cb){
	return ra==rb||ca==cb;
}
inline void Init(){
	n=Read();
	r1=Read(),c1=Read();
	r2=Read(),c2=Read();
	r3=Read(),c3=Read();
	if(Check(r1,c1,r2,c2)&&Check(r1,c1,r3,c3)) midr=r1,midc=c1;
	if(Check(r3,c3,r2,c2)&&Check(r1,c1,r2,c2)) midr=r2,midc=c2;
	if(Check(r1,c1,r3,c3)&&Check(r2,c2,r3,c3)) midr=r3,midc=c3;
	xx=Read(),yy=Read();
	return ;
}
inline int Abs(int x){
	return x>0?x:-x;
}
inline void Solve(){
	//printf("midr=%d midc=%d\n",midr,midc);
	if(xx==midr||yy==midc){
		puts("YES");
		return ;
	}
	if((midr==1||midr==n)&&(midc==1||midc==n)){
		puts("NO");
		return ;
	}
	if(midr%2!=xx%2&&midc%2!=yy%2) puts("NO");
	else puts("YES");
	return ;
}
int T;
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}