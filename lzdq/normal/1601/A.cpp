#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=2e5+5;
int n;
int cnt[30],c0;
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int g,ans[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		g=0;
		for(int i=1; i<=n; i++){
			ans[i]=0;
			int x;
			scanf("%d",&x);
			if(x){
				for(int j=0; j<30; j++)
					cnt[j]+=x&1,x>>=1;
			}
		}
		for(int i=0; i<30; i++)
			g=gcd(g,cnt[i]);
		for(int i=1; i<=n; i++)
			if(g%i==0) printf("%d ",i);
		puts("");
	}
	return 0;
}