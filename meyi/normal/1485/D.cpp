#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=510;
int a,m,n;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i,printf("\n"))
		for(ri j=1;j<=m;++j)
			scanf("%d",&a),printf("%d ",((i+j)&1)?720720:(720720-a*a*a*a));
	return 0;
}