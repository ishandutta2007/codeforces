#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int ans,cnt[maxn],m,n,q;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		if(!cnt[x])++ans;
		++cnt[x];
	}
	scanf("%d",&q);
	while(q--){
		ri op,x,y;
		scanf("%d",&op);
		if(op==1){
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			if(!cnt[x])++ans;
			++cnt[x];
		}
		else if(op==2){
			scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			--cnt[x];
			if(!cnt[x])--ans;
		}
		else printf("%d\n",n-ans);
	}
	return 0;
}