#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_set>
#include<cmath>
#include<set>
#include<map>
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
//
LL s,f[2][140][2],ans;
LL dp(int ones,int len1,int len2,LL tot){
	memset(f,0,sizeof f);
	int i,now=0,a,b,d,j;
	f[0][0][0]=1;
	for(i=0;(1ll<<i)<=tot;i++){
		now^=1;
		memset(f[now],0,sizeof f[now]);
		for(a=0;a<2;a++)
			if(!a||i<len1)
				for(b=0;b<2;b++)
					if(!b||i<len2)
						for(d=0;d<2;d++)
							if(((a+b+d)&1)==((tot>>i)&1))
								for(j=0;j+a+b<=ones;j++)
									f[now][j+a+b][(a+b+d)>>1]+=f[now^1][j][d];
	}
	return f[now][ones][0];
}
int main()
{
	Read(s);
	int a,b,i;
	LL lca,cnt,rm,tot;
	for(a=0;a<=58;a++)
		for(b=0;b<=58;b++){
			cnt=(1ll<<(a+1))-1+(1ll<<(b+1))-1-1;
			lca=s/cnt;
			if(!lca)
				continue;
			rm=s%cnt-(1ll<<b)+1;
			for(i=0;i<=a+b;i++){
				tot=rm+i;
				if(tot<0||(tot&1))
					continue;
				ans+=dp(i,a-1,b-1,tot>>1);
			}
		}
	printf("%I64d\n",ans);
}