#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,a[MAXN];
bool ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=1;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(i<100){
				bool t=0;
				for(int j=2; j<=i+1; j++)
					if(a[i]%j) t=1;
				if(!t) ans=0;
			}
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}