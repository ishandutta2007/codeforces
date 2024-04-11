#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],ans[maxn],b[maxn],id[maxn],n;
vector<int>fr[maxn];
inline bool cmp(const int &x,const int &y){return x-a[x]<y-a[y];}
int main(){
	memset(ans,-1,sizeof ans);
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),id[i]=i;
	for(ri i=1;i<=n;++i)scanf("%d",b+i),fr[i+b[i]].push_back(i);
	sort(id+1,id+n+1,cmp);
	ri cur=1,pre=0;
	while(1){
		bool flag=true;
		ri nxt=0;
		while(cur<=n&&id[cur]-a[id[cur]]<=pre){
			flag=false;
			ri k=id[cur];
			ans[k]=pre;
			for(ri i=0;i<fr[k].size();++i)ckmax(nxt,fr[k][i]);
			++cur;
		}
		if(flag)break;
		pre=nxt;
	}
	if(~ans[n]){
		ri cnt=1;
		for(ri i=ans[n];i;++cnt,i=ans[i+b[i]]);
		printf("%d\n",cnt);
		for(ri i=ans[n];i;++cnt,i=ans[i+b[i]])printf("%d ",i);
		putchar(48);
	}
	else puts("-1");
	return 0;
}