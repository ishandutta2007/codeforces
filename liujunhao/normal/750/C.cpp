#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
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
#define MAXN 200000
int n,c[MAXN+10],d[MAXN+10];
int mx,mx2=0x80000000,now,mi1=0x7fffffff;
int main()
{
	Read(n);
	int i;
	for(i=1;i<=n;i++){
		Read(c[i]),Read(d[i]);
		if(d[i]==2)
			mx2=max(mx2,now);
		else
			mi1=min(mi1,now);
		now+=c[i];
		mx=max(mx,now);
	}
	if(mi1<=mx2)
		puts("Impossible");
	else if(mx2==0x80000000)
		puts("Infinity");
	else
		printf("%d\n",now-mx2+1899);
}