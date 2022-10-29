#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n,root,r;
int p[200005];
int vis[200005];

int main(){
	r=0,root=-1;
	memset(vis,-1,sizeof(vis));
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",p+i);p[i]--;
		if(p[i]==i){
			if(root<0)root=i;
//			else {
//				p[i]=root;
//				r++;
//			}
		}
	}
	for(int i=0;i<n;++i){
		int x=i;
		while(vis[x]<0){
			vis[x]=i;
			x=p[x];
		}
		if(vis[x]==i&&x!=root){
			r++;
			if(root<0){p[x]=x;root=x;}
			else p[x]=root;
		}
	}
	printf("%d\n%d",r,p[0]+1);
	for(int i=1;i<n;++i){
		printf(" %d",p[i]+1);
	}
	puts("");
	return 0;
}