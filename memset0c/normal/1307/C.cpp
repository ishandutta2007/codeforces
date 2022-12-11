// 
#include<bits/stdc++.h>
#define int long long
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=1e5+10;
int n,ans;
char s[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	scanf("%s",s+1),n=strlen(s+1),s[++n]='z'+1;
	for(int a=1;a<=27;a++)for(int b=1;b<=27;b++){
		int sum=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]-'a'+1==b)sum+=cnt;
			if(s[i]-'a'+1==a)cnt++;
		}
		ans=std::max(ans,sum);
	}
	print(ans,'\n');
}