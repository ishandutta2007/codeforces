#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>  
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
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
#define MOD 1000000007
#define MAXN 75
int f[MAXN+10][1<<20],n,ans,nxt[MAXN+10];
char s[MAXN+10];
int main()
{
	Read(n);
	scanf("%s",s+1);
	int i,t=1<<20,s,j;
	nxt[n+1]=n+1;
	for(i=n;i;i--)
		nxt[i]=(::s[i]=='1')?i:nxt[i+1];
	for(i=0;i<=n;i++)
		f[i][0]=1;
	for(i=0;i<=n;i++){
		for(s=0;s<t;s++){
			int now=0;
			for(j=nxt[i+1];j<=n;j++){
				now=(now<<1)|(::s[j]-'0');
				if(now>20)
					break;
				if(now)
					(f[j][s|(1<<(now-1))]+=f[i][s])%=MOD;
			}
			if(s){
				now=__builtin_popcount(s);
				if((1<<now)-1==s)
					(ans+=f[i][s])%=MOD;
			}
		}
	}
	printf("%d\n",ans);
}