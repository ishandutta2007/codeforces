#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n;
int a[MAXN],b[MAXN];
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		bool pos=0,neg=0,ans=1;
		for(int i=1; i<=n; i++){
			if(a[i]>b[i]){
				if(!neg) ans=0;
			}else if(a[i]<b[i]&&!pos) ans=0;
			if(a[i]==1) pos=1;
			else if(a[i]==-1) neg=1;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}