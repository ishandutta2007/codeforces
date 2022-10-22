#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
int ans;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		ans=0;
		for(int i=1; i<n; i++){
			if(i>1&&a[i-1]==a[i]) continue;
			int x=1,w=i+1;
			while(w<=n){
				x++;
				w=lower_bound(a+w+1,a+n+1,a[w]*2-a[i])-a;
			}
			ans=max(ans,x);
		}
		printf("%d\n",n-ans);
	}
	return 0;
}