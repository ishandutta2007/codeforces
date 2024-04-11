#include<cstdio>
#include<cstring>
const int N=2e5+5;
const int Mod=998244353;
int len;
char s[N];
inline void add(int&x,const int y){
	x+=y;
	if(x>=Mod) x-=Mod;
	return ;
}
inline void sub(int&x,const int y){
	x-=y;
	if(x<0) x+=Mod;
	return ;
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
int f[N][2][2][2][2][2][2];
int ans;
inline void Solve(){
	scanf("%s",s+1);
	len=strlen(s+1);
	f[0][0][0][0][1][1][1]=1;
	for(int i=1;i<=len;i++)
		for(int fa=0;fa<=1;fa++)
			for(int fb=0;fb<=1;fb++)
				for(int fc=0;fc<=1;fc++){
					int mxa,mxb,mxc;
					if(fa) mxa=s[i]-'0';
					else mxa=1;
					if(fb) mxb=s[i]-'0';
					else mxb=1;
					if(fc) mxc=s[i]-'0';
					else mxc=1;
					for(int gx=0;gx<=1;gx++)
						for(int gy=0;gy<=1;gy++)
							for(int j=0;j<=1;j++){
								for(int a=0;a<=mxa;a++)
									for(int b=0;b<=mxb;b++)
										for(int c=0;c<=mxc;c++){
											int x=a^b,y=a^c,z=b^c;
											if(!gx&&x>z) continue ;
											if(!gy&&y>z) continue ;
											int fa1=(fa&&a==mxa),fb1=(fb&&b==mxb),fc1=(fc&&c==mxc);
											add(f[i][j||(x==1&&y==1)][gx||x<z][gy||y<z][fa1][fb1][fc1],f[i-1][j][gx][gy][fa][fb][fc]);
										}
							}
				}
	int ans=0;
	for(int fa=0;fa<=1;fa++)
		for(int fb=0;fb<=1;fb++)
			for(int fc=0;fc<=1;fc++)
				add(ans,f[len][1][1][1][fa][fb][fc]);
	ans=3ll*ans%Mod;
	Print(ans);
	return ;
}
int main(){
	Solve();
	return 0;
}