#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
int ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=0;
		int l=1,r=n;
		while(1){
			while(l<=n&&a[l]==0) l++;
			while(r>0&&a[r]==1) r--;
			if(l>r) break;
			ans++;
			l++,r--;
		}
		printf("%d\n",ans);
	}
	return 0;
}