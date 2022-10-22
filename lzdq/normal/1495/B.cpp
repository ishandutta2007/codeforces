#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,m,a[MAXN],b[MAXN],c[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	int mx=0;
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		if(i>1&&a[i]>a[i-1]) b[i]=b[i-1]+1;
	}
	for(int i=n-1; i; i--)
		if(a[i]>a[i+1]) c[i]=c[i+1]+1;
	for(int i=1; i<=n; i++)
		mx=max(mx,max(b[i],c[i]));
	int cnt=0;
	for(int i=1; i<=n; i++){
		if(mx==b[i]) cnt++;
		if(mx==c[i]) cnt++;
	}
	if(cnt==2){
		for(int i=1; i<=n; i++){
			if(b[i]!=c[i]) continue;
			if(b[i]!=mx) continue;
			if(cnt!=2) continue;
			if(mx&1) continue;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}