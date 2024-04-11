#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=6e5+5;
typedef long long ll;
int n,b[MAXN];
ll ans[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",b+i);
		ans[b[i]-i+n]+=b[i];
	}
	ll res=0;
	for(int i=1; i<MAXN; i++)
		res=max(res,ans[i]);
	printf("%I64d\n",res);
	return 0;
}