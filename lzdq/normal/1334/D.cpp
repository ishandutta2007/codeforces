#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
typedef long long ll;
int n;
ll l,r;
ll s[MAXN];
ll k,p[MAXN];
int a[MAXN];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d%lld%lld",&n,&l,&r);
		for(int i=1; i<=n; i++){
			if(i==n) s[i]=1;
			else s[i]=n*2-i*2;
		}
		int x=0,y=0;
		for(int i=1; !y; i++){
			s[i]+=s[i-1];
			if(!x&&s[i]>=l) x=i;
			if(r<=s[i]) y=i;
		}
		//printf("x %d y %d\n",x,y);
		k=s[x-1];
		*p=0;
		for(int i=x; i<=y; i++){
			if(i==n){
				p[++*p]=++k,a[*p]=1;
				break;
			}
			for(int j=i+1; j<=n; j++){
				p[++*p]=++k,a[*p]=i;
				p[++*p]=++k,a[*p]=j;
			}
		}
		for(int i=1; i<=*p; i++)
			if(l<=p[i]&&p[i]<=r) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}