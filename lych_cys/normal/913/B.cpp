#include<bits/stdc++.h>
#define N 10009
using namespace std;

int n,fa[N],dgr[N],sum[N];
int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int main(){
	scanf("%d",&n);
	int i;
	for (i=2; i<=n; i++){
		scanf("%d",&fa[i]);
		dgr[i]++; dgr[fa[i]]++;
	}
	for (i=1; i<=n; i++) if (i>1 && dgr[i]==1) sum[fa[i]]++;
	for (i=1; i<=n; i++) if (i==1 || dgr[i]>1)
		if (sum[i]<3){
			puts("No"); return 0;
		}
	puts("Yes"); return 0;
	return 0;
}