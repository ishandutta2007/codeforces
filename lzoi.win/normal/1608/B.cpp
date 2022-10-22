#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,a,b;
int p[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&n,&a,&b);
		if(abs(a-b)>1||a+b>n-2){
			puts("-1");
			continue;
		}
		if(a>b){
			for(int i=1; i<=a*2; i++)
				if(i&1) p[i]=i/2+1;
				else p[i]=n-i/2+1;
			for(int i=a*2+1; i<=n; i++)
				p[i]=p[i-1]-1;
		}
		if(a==b){
			for(int i=1; i<=a*2+1; i++)
				if(i&1) p[i]=i/2+1;
				else p[i]=n-i/2+1;
			for(int i=a*2+2; i<=n; i++)
				p[i]=p[i-1]+1;
		}
		if(a<b){
			swap(a,b);
			for(int i=1; i<=a*2; i++)
				if(i&1) p[i]=i/2+1;
				else p[i]=n-i/2+1;
			for(int i=a*2+1; i<=n; i++)
				p[i]=p[i-1]-1;
			for(int i=1; i<=n; i++)
				p[i]=n-p[i]+1;
		}
		for(int i=1; i<=n; i++)
			printf("%d ",p[i]);
		puts("");
	}
	return 0;
}