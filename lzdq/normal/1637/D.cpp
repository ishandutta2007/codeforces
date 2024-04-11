#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=105,INF=0x3fffffff;
int n,a[MAXN],b[MAXN],s;
bitset<MAXN*MAXN> f;
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		s=0;
		f.reset();
		f[0]=1;
		for(int i=1; i<=n; i++){
			s+=a[i]+b[i];
			f=f<<a[i]|f<<b[i];
		}
		ans=INF;
		for(int i=0; i<=n*100; i++)
			if(f[i]) ans=min(ans,i*i+(s-i)*(s-i));
		for(int i=1; i<=n; i++)
			ans+=(n-2)*(a[i]*a[i]+b[i]*b[i]);
		printf("%d\n",ans);
	}
	return 0;
}