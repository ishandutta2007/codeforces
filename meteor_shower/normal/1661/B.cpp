#include<cstdio>
const int N=32768;
int f[N];
int n;
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
inline void print(const int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const int x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
inline void Init_F(){
	f[N-1]=1;
	for(register int i=N-2;i>=1;i--){
		f[i]=f[i+1]+1;
		if(i*2<N) f[i]=Min(f[i],f[i*2]+1);
		int ss=N,x=i;
		while(x%2==0){
			x/=2;
			ss/=2;
		}
		x=0;
		while(ss%2==0){
			ss/=2;
			x++;
		}
		if(x<f[i]) f[i]=x;
	}
	f[0]=0;
	return ;
}
int main(){
	Init_F();
	for(n=Read();n;n--){
		int x=Read();
		Print(f[x]);
	}
	return 0;
}