#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());a[n+1]=0;
		printf(a[1]-a[2]>1?"No\n":"Yes\n");
	}
	return 0;
}