#include<cstdio>
#include<algorithm>
#define MAXN 200000
using namespace std;
char s[MAXN+10];
int n,t,st,la,tm;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int main()
{
	Read(n),Read(t);
	scanf("%s",s+1);
	int i;
	for(i=1;i<=n;i++)
		if(s[i]=='.')
			break;
	st=i;
	for(i=st+1;i<=n;i++){
		if(s[i]>='5')
			break;
	}
	if(i>n){
		puts(s+1);
		return 0;
	}
	la=i;
	int tag=1,tt=1;
	for(i=la-1;i>st&&tt<=t;i--){
		if(tag){
			s[i]++;
			if(s[i]>'9'){
				la=i;
				tag=1;
				continue;
			}
			tag=0;
		}
		if(s[i]>='5'&&tt<t)
			la=i,tt++,tag=1;
	}
	if(tag){
		s[st]=0;
		for(i=st-1;i;i--){
			s[i]+=tag;
			if(s[i]>'9')
				s[i]='0',tag=1;
			else
				tag=0;
		}
		if(tag){
			s[0]='1';
			puts(s);
		}
		else
			puts(s+1);
	}
	else{
		s[la]=0;
		puts(s+1);
	}
}