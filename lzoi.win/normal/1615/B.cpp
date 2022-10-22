#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
int a[18][MAXN];
int main(){
	n=2e5;
	for(int i=1; i<=n; i++)
		for(int j=0; j<18; j++)
			if(i&1<<j) a[j][++*a[j]]=i;
	int _; scanf("%d",&_);
	while(_--){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=1;
		for(int i=0; i<18; i++)
			ans=max(ans,(int)(upper_bound(a[i]+1,a[i]+*a[i]+1,r)-lower_bound(a[i]+1,a[i]+*a[i]+1,l)));
		printf("%d\n",r-l+1-ans);
	}
	return 0;
}