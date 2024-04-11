#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define LD long double

int n,cur;
char c,s[100];

int main(){
	scanf("%d",&n);
	c=getchar();
	while(n--){
		c=getchar();
		if(c<='1') continue;
		if(c=='2') s[++cur]='2';
		if(c=='3') s[++cur]='3';
		if(c=='4') s[++cur]='2',s[++cur]='2',s[++cur]='3';
		if(c=='5') s[++cur]='5';
		if(c=='6') s[++cur]='3',s[++cur]='5';
		if(c=='7') s[++cur]='7';
		if(c=='8') s[++cur]='2',s[++cur]='2',s[++cur]='2',s[++cur]='7';
		if(c=='9') s[++cur]='7',s[++cur]='3',s[++cur]='3',s[++cur]='2';
	}
	sort(s+1,s+cur+1);
	dep(i,cur,1) putchar(s[i]);
}