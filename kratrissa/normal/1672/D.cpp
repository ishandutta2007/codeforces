#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,a[N],b[N],lst[N],nxt[N],c[N];
void solve(){
	scanf("%d",&n),fill(lst,lst+n+1,n+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i;i--)nxt[i]=lst[a[i]],lst[a[i]]=i,c[i]=1;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1,t=1;i<=n;i++){
		int p=lst[b[i]];
		for(int j=t;j<p;j++)
			if(nxt[lst[a[j]]]==n+1){printf("NO\n");return;}
			else c[nxt[lst[a[j]]]]+=c[lst[a[j]]],lst[a[j]]=nxt[lst[a[j]]];
		t=p;
		if((--c[p])==0)lst[b[i]]=nxt[p],t++;
	}
	printf("YES\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}