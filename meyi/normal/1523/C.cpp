#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1010;
int a[maxn],ans[maxn],cnt[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		memset(cnt,0,sizeof cnt);
		ans[cnt[1]=1]=1;
		putchar('1'),putchar(10);
		for(ri i=2;i<=n;++i){
			cnt[i]=cnt[i-1];
			if(a[i]==1)ans[++cnt[i]]=1;
			else{
				for(ri j=cnt[i];j;--j)
					if(ans[j]+1==a[i]){
						ans[cnt[i]=j]=a[i];
						break;
					}
			}
			for(ri j=1;j<=cnt[i];++j)printf("%d%c",ans[j],j==cnt[i]?' ':'.');
			putchar(10);
		}
	}
	return 0;
}