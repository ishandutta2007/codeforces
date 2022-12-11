#include<bits/stdc++.h>
#define ll long long 
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
int n,m;
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m);
	if(n==1&&m==1){puts("0");return 0;}
	if(n==1||m==1){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				print(i+j," \n"[j==m]);
		return 0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			// printf("%d %d : %d\n",i,j,i*(j+m));
			print((ll)j*(i+m)," \n"[j==m]);
		}
}