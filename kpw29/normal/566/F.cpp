#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000111;
int wyn[MAXN];

main(){
	int n;scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		wyn[a]++;
		ans=max(ans,wyn[a]);
		for(int j=2*a;j<MAXN;j+=a){
			wyn[j]=max(wyn[j],wyn[a]);
		}
		//printf("%d %d\n",a,wyn[a]);
	}
	printf("%d\n",ans);
}