#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int a,b,c,d;
ll f[MAXN],ans;
int main() {
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int i=a; i<=b; i++)
		f[i+b]++,f[i+c+1]--;
	for(int i=1; i<=1e6; i++) f[i]+=f[i-1];
	for(int i=1e6-1;i>=0;i--) f[i]+=f[i+1];
	for(int i=c+1; i<=d+1; i++) ans+=f[i];
	printf("%lld\n",ans);
	return 0;
}