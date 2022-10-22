#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a,ans[maxn],b,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&a,&b);
		set<int>s;
		for(ri i=1;i<=n;++i)
			if(i!=a&&i!=b)
				s.insert(i);
		ans[1]=a,ans[n]=b;
		bool flag=false;
		ri mid=n>>1;
		for(ri i=2;i<n;++i){
			if(i<=mid){
				ans[i]=*--s.end();
				s.erase(ans[i]);
				if(ans[i]<a)flag=true;
			}
			else{
				ans[i]=*s.begin();
				s.erase(ans[i]);
				if(ans[i]>b)flag=true;
			}
		}
		if(flag)puts("-1");
		else{
			for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
			printf("\n");
		}
	}
}