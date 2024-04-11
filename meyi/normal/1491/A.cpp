#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],cnt,n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),cnt+=a[i];
	while(m--){
		int op,x;
		scanf("%d%d",&op,&x);
		if(op&1){
			if(a[x])--cnt;
			else ++cnt;
			a[x]=!a[x];
		}
		else printf("%d\n",cnt>=x);
	}
	return 0;
}