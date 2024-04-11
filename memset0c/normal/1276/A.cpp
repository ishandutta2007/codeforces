#include<bits/stdc++.h>
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
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=2e5+10;
int T,n,ans,tag[N];
char s[N];
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		scanf("%s",s+1),n=strlen(s+1),ans=0;
		for(int i=1;i<=n;i++)tag[i]=0;
		for(int i=1;i+2<=n;i++)if(s[i]=='o'&&s[i+1]=='n'&&s[i+2]=='e')++ans,tag[i+1]=1;
		for(int i=1;i+2<=n;i++)if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o')++ans,tag[i+1]=1;
		for(int i=1;i+4<=n;i++)if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e')--ans,tag[i+1]=tag[i+3]=0,tag[i+2]=1;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)if(tag[i])print(i,' ');
		putchar('\n');
	}
}