#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,p[200005];bool vis[200005];int sz;
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++) scanf("%d",&p[i]);
	int t=0,j;
	for (i=1; i<=n; i++){int x;scanf("%d",&x);t^=x;}
	for (i=1; i<=n; i++) if (!vis[i]){sz++;
		for (j=i; !vis[j]; j=p[j]){vis[j]=1;}
	}
	cout<<(sz>1?sz:0)+(t^1);
	return 0;
}