#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",a+1,a+2,a+3);
		ri ans=0;
		for(auto i:{1,2,3})
			if(a[i])
				--a[i],++ans;
		sort(a+1,a+4,greater<int>());
		if(a[1]&&a[2])--a[1],--a[2],++ans;
		if(a[1]&&a[3])--a[1],--a[3],++ans;
		if(a[2]&&a[3])--a[2],--a[3],++ans;
		if(a[1]&&a[2]&&a[3])--a[1],--a[2],--a[3],++ans;
		printf("%d\n",ans);
	}
	return 0;
}