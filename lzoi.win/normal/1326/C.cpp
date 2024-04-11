#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,Mod=998244353;
int n,k;
int p[MAXN],q[MAXN];
bool b[MAXN];
ll ans1,ans2;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++)
		scanf("%d",p+i),q[p[i]]=i;
	for(int i=0; i<k; i++)
		b[q[n-i]]=1,ans1+=n-i;
	int w=0;
	ans2=1;
	for(int i=1; i<=n; i++)
		if(b[i]){
			if(w) ans2=ans2*(i-w)%Mod;
			w=i;
		}
	printf("%I64d %I64d\n",ans1,ans2);
	return 0;
}