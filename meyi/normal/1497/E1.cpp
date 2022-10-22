#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxa=1e7+1,maxn=2e5+10;
int a[maxn],ans,lp[maxa],lst,m,n,t;
vector<int>pri;
bool vis[maxa];
inline int calc(int k){
	ri ret=1;
	while(lp[k]){
		ri p=lp[k];
		bool flag=false;
		while(k%p==0)k/=p,flag=!flag;
		if(flag)ret*=p;
	}
	return ret;
}
int main(){
	for(ri i=2;i<maxa;++i){
		if(!lp[i])lp[i]=i,pri.push_back(i);
		for(ri j=0;j<pri.size()&&i*pri[j]<maxa;++j)lp[i*pri[j]]=pri[j];
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ans=lst=1;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			a[i]=calc(a[i]);
			if(vis[a[i]]){
				++ans;
				for(ri j=lst;j<i;++j)vis[a[j]]=false;
				lst=i;
			}
			vis[a[i]]=true;
		}
		for(;lst<=n;++lst)vis[a[lst]]=false;
		printf("%d\n",ans);
	}
	return 0;
}