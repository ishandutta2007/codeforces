#include<cstdio>
int n,m;
int mnx,mny;
int T;
char s[10][10];
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
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
int main(){
	for(T=Read();T;T--){
		n=mnx=Read();
		m=mny=Read();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++){
				if(s[i][j]=='R'){
					mnx=Min(mnx,i);
					mny=Min(mny,j);
				}
			}
		}
		if(s[mnx][mny]=='R') puts("YES");
		else puts("NO");
	}
	return 0;
}