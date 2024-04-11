#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a[maxn],b[maxn],n,s,t,_tm;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d%d",a+i,b+i);
		s=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",&_tm);
			s+=a[i]-b[i-1]+_tm;
			if(i<n){
				int tmp=s;
				if(s<b[i])s=b[i];
				if(s-tmp<ceil((b[i]-a[i])*0.5))s=tmp+ceil((b[i]-a[i])*0.5);
			}
		}
		printf("%d\n",s);
	}
}