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
#define MAXN 100000
int n,cnt[MAXN+10],ans=1;
int main()
{
	Read(n);
	int i,a,ret,j;
	for(i=1;i<=n;i++){
		Read(a);
		cnt[a]++;
	}
	for(i=2;i<=100000;i++){
		ret=0;
		for(j=i;j<=100000;j+=i)
			ret+=cnt[j];
		ans=max(ans,ret);
	}
	printf("%d\n",ans);
}