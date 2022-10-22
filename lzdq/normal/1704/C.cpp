#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m,a[MAXN],b[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=m; i++)
			scanf("%d",a+i);
		sort(a+1,a+m+1);
		for(int i=1; i<m; i++)
			b[i]=a[i+1]-a[i]-1;
		b[m]=a[1]+n-a[m]-1;
		sort(b+1,b+m+1);
		reverse(b+1,b+m+1);
		ans=0;
		for(int i=1; i<=m; i++){
			if(b[i]<=(i-1)*4) break;
			int x=b[i]-(i-1)*4;
			if(x>1) ans+=x-1;
			else ans++;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}