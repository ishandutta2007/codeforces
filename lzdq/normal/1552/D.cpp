#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[20];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		bool ans=0;
		for(int i=1; i<1<<n; i++){
			for(int j=i; j; j=j-1&i){
				int s=0;
				for(int k=1; k<=n; k++)
					if(i&1<<k-1) s+=j&1<<k-1?a[k]:-a[k];
				if(!s){
					ans=1;
					break;
				}
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}