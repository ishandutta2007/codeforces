#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
ll sum;
bool ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=1;
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		while(n&&a[n]==0) n--;
		if(n){
			sum=0;
			for(int i=1; i<=n; i++){
				sum+=a[i];
				if(i<n&&sum<=0) ans=0;
			}
			if(sum!=0) ans=0;
		}
		if(ans) puts("Yes");
		else puts("No");
	}
	return 0;
}