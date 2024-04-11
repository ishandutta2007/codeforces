#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
bool Check(int k){
	int w=1;
	for(int i=1; i<=n; i++)
		if(a[i]>=k-w&&b[i]>=w-1&&++w>k) return 1;
	return 0;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d%d",a+i,b+i);
		int l=1,r=n;
		while(l<r){
			int mid=l+r+1>>1;
			if(Check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}