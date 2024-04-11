#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int cnt,a[maxn],m,n,t_case;
vector<int>ans;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		if(n==1){printf("0\n");continue;}
		ans.clear();
		for(ri i=n;i>1;--i){
			ri d=min(a[i-1],a[i]);
			ans.pb(i),ans.pb(i-1),ans.pb(2e9-n+i),ans.pb(d);
			a[i]=2e9-n+i;
			a[i-1]=d;
		}
		cnt=0;
		while(gcd(a[2]-cnt,a[1])>1)++cnt;
		printf("%d\n",SZ(ans)/4);
		for(ri i=0;i<SZ(ans);++i)printf("%d%c",i%4==2?ans[i]-cnt:ans[i],i%4==3?'\n':' ');
	}
	return 0;
}