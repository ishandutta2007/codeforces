#include<cstdio>
#include<cstring>
using namespace std;
const int N=10002;
int n,T,p[27],q[27],i,o;
char s[N],t[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",s+1,t+1);
		memset(p,0,sizeof(p));
		memset(q,0,sizeof(q));
		n=0;
		while(s[n+1])n++;
		for(i=1;i<=n;i++){
			p[s[i]-97]++;
			q[t[i]-97]++;
		}
		o=0;
		for(i=0;i<26;i++)
			if(p[i]&&q[i])
				o=1;
		printf("%s\n",o?"YES":"NO");
	}
}