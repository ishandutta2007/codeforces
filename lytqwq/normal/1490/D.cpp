#include<bits/stdc++.h>
using namespace std;
const int N=110;
long long int T,n,a[N],ans[N];
void f(int l,int r,int depth){
	if(l>r){
		return ;
	}
	int maxn=0,wz=0;
	for(int i=l;i<=r;i++){
		if(maxn<a[i]){
			maxn=a[i];
			wz=i;
		}
	}
	ans[wz]=depth+1;
	f(l,wz-1,depth+1);
	f(wz+1,r,depth+1);
}
int main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		f(1,n,-1);
		for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}