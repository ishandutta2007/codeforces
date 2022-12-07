#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;
int vis[maxn],n,a[maxn],b[maxn],m;
bool ch[maxn];

int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		vis[a[i]]++;
	}
	for(int i=1; i<=n; i++)
		if(!vis[i])b[++m]=i;
	int l=0;
	b[m+1]=n+10;
	for(int i=1; i<=n; i++) {
		if(vis[a[i]]==1)continue;
		if(ch[a[i]]) {
            vis[a[i]]--;
			a[i]=b[++l];
			continue;
		}
		if(a[i]>b[l+1]) {
            vis[a[i]]--;
			a[i]=b[++l];
		} else {
			ch[a[i]]=true;
		}
	}
	printf("%d\n",m);
	for(int i=1; i<=n; i++)printf("%d%c",a[i],i==n?'\n':' ');
	return 0;
}