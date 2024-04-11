#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 100000
int n;
char s[MAXN+10];
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
int solve0(){
	int i,cnt0=0,cnt1=0;
	for(i=1;i<=n;i++)
		if(i&1){
			if(s[i]!=0)
				cnt1++;
		}
		else{
			if(s[i]!=1)
				cnt0++;
		}
	return max(cnt0,cnt1);
}
int solve1(){
	int i,cnt0=0,cnt1=0;
	for(i=1;i<=n;i++)
		if(i&1){
			if(s[i]!=1)
				cnt0++;
		}
		else{
			if(s[i]!=0)
				cnt1++;
		}
	return max(cnt0,cnt1);
}
int main()
{
	Read(n);
	scanf("%s",s+1);
	int i;
	for(i=1;i<=n;i++){
		if(s[i]=='r')
			s[i]=0;
		else
			s[i]=1;
	}
	printf("%d\n",min(solve1(),solve0()));
}