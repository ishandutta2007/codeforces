#include<bits/stdc++.h>
#define N 200009
using namespace std;

int n,a[N],nxt[N]; bool vis[N];
struct cmp{
	bool operator ()(int x,int y){
		return a[x]>a[y] || a[x]==a[y] && x<y;
	}
};
set<int,cmp> S; set<int,cmp>:: iterator it;
int main(){
	scanf("%d",&n);
	int i,j;
	a[0]=0; for (i=1; i<=n; i++) scanf("%d",&a[i]);
	S.insert(0);
	for (i=1; i<=n; i++){
		it=S.lower_bound(i);
		//cout<<i<<' '<<(*it)<<endl;
		if ((*it)==0){
			S.insert(i);
		} else{
			nxt[*it]=i; S.erase(*it); S.insert(i);
		}
	}
	for (i=1; i<=n; i++) if (!vis[i]){
		for (j=i; j; j=nxt[j]){ printf("%d ",a[j]); vis[j]=1; }
		puts("");
	}
	return 0;
}