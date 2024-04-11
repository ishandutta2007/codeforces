#include<bits/stdc++.h>
#define ll long long
// #define int long long
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=2e5+10;
int T,n,fl[N];
char s[N],t[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(T);
	while(T--){
		read(n);
		scanf("%s",s);
		for(int i=0;i<n;i++)t[i]=s[i],fl[i]=0;
		std::sort(t,t+n);
		int j=0;
		for(int i=0;i<n;i++)if(s[i]==t[j])j++,fl[i]=1;
		for(int i=0;i<n;i++)if(s[i]==t[j]&&!fl[i])j++,fl[i]=2;
		bool res=true;
		for(int i=0;i<n;i++)if(!fl[i])res=false;
		if(res){
			for(int i=0;i<n;i++)putchar(fl[i]+'0');
			putchar('\n');
		}else{
			puts("-");
		}
	}
}