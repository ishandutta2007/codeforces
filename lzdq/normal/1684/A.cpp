#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
int a[100],ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		*a=0;
		while(n){
			a[++*a]=n%10;
			n/=10;
		}
		if(*a==2) ans=a[1];
		else{
			ans=9;
			for(int i=1; i<=*a; i++)
				ans=min(ans,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}