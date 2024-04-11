#include<cstdio>
#include<algorithm>
#include<cstring>
#include<bitset>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
int n,a[MAXN];
bitset<MAXN> f,g;
bool Check(const int k){
	g.reset();
	for(int i=0; i<=k; i++) g[i]=1;
	f=g;
	for(int i=1; i<=n; i++)
		f=((f>>a[i])|(f<<a[i]))&g;
	return f.count();
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		int l=1,r=2000;
		while(l<r){
			int mid=l+r>>1;
			if(Check(mid)) r=mid;
			else l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}