#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
template<class T>
void Read(T &x){
	static char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			if(f)
				x=-x;
			ungetc(c,stdin);
			return;
		}
	}
}
#define MAXN 100000
int n,c[MAXN+10],k;
long long ans,sum;
bool vis[MAXN+10];
void read(){
	Read(n),Read(k);
	int i;
	for(i=1;i<=n;i++){
		Read(c[i]);
		if(i>1)
			ans+=c[i]*c[i-1];
		sum+=c[i];
	}
	ans+=c[1]*c[n];
}
void solve(){
	int x;
	for(int i=1;i<=k;i++){
		Read(x);
		vis[x]=1;
		long long tsum=sum-c[x];
		if(!vis[x%n+1])
			tsum-=c[x%n+1];
		if(!vis[(x+n-2)%n+1])
			tsum-=c[(x+n-2)%n+1];
		ans+=tsum*c[x];
		sum-=c[x];
	}
}
int main()
{
	read();
	solve();
	printf("%I64d\n",ans);
}