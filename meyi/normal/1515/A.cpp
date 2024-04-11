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
int a[maxn],m,n,s,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		s=0;
		for(ri i=1;i<=n;++i)scanf("%d",a+i),s+=a[i];
		if(s==m){puts("NO");continue;}
		puts("YES");
		bool flag=false;
		for(ri i=2,t=0;i<=n;++i){
			if(t+a[i]==m)printf("%d ",a[1]),t+=a[1],flag=true;
			printf("%d ",a[i]);
			t+=a[i];
		}
		if(!flag)printf("%d",a[1]);
		printf("\n");
	}
	return 0;
}