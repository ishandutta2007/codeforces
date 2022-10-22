#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int MAXN=105;
ll fib[MAXN];
int tot;
ull Calc(int x){
	ull res=0;
	for(int i=tot; i; i--)
		if(x>=fib[i]){
			res|=1ull<<i-1;
			x-=fib[i];
		}
	if(x) return ~0ull;
	return res;
}
int n,a[MAXN];
ull b[MAXN],c[MAXN];
bool ans;
int cnt[MAXN];
int main(){
	fib[0]=fib[1]=1;
	for(tot=2; (fib[tot]=fib[tot-1]+fib[tot-2])<=1e9; tot++);// printf("%lld\n",fib[tot]);
	//printf("tot %d\n",tot);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		if(n==1) ans=(a[1]==1);
		else{
			for(int i=1; i<=n; i++){
				b[i]=Calc(a[i]);
				c[i]=Calc(a[i]-1);
			}
			ans=0;
			for(int i=1; i<=n; i++){
				if(c[i]&1) continue;
				ull x=c[i];
				for(int j=1; j<=n; j++)
					if(i!=j){
						if(x&b[j]) x=~0ull;
						else x|=b[j];
					}
				if(~x){
					x++;
					if((x&-x)==x){
						ans=1;
						break;
					}
				}
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}