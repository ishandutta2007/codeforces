#include<cstdio>
int n,r,b;
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
inline void Solve(){
	int cnt=r/(b+1);
	int res=r-cnt*(b+1);
	//if(cnt*(b+1)<r) cnt++;
	for(register int i=1;i<=b;i++){
		if(res){
			for(register int j=1;j<=cnt+1;j++)
				putchar('R');
			res--;
			r-=cnt+1;
		}
		else{
			for(register int j=1;j<=cnt;j++)
				putchar('R');
			//res--;
			r-=cnt;
		}
		putchar('B');
		//r-=cnt;
	}
	while(r--) putchar('R');
	putchar('\n');
	return ;
}
int T;
int main(){
	for(T=Read();T;T--){
		n=Read();
		r=Read();
		b=Read();
		Solve();
	}
	return 0;
}