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
		scanf("%d",&n);
		ri cnt1=0,cnt2=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]&1)++cnt1;
			else ++cnt2;
		}
		if(cnt1&1)puts("NO");
		else{
			if(!cnt1&&(cnt2&1))puts("NO");
			else puts("YES");
		}
	}
	return 0;
}