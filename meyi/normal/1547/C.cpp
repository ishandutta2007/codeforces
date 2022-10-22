#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],k,m,n,st[maxn],tp,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&k,&n,&m);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=m;++i)scanf("%d",b+i);
		bool flag=false;
		tp=0;
		for(ri i=0,j=0;i<n||j<m;){
			while(i<n&&!a[i+1])++k,++i,st[++tp]=0;
			while(j<m&&!b[j+1])++k,++j,st[++tp]=0;
			if(i<n&&k>=a[i+1])++i,st[++tp]=a[i];
			else if(j<m&&k>=b[j+1])++j,st[++tp]=b[j];
			else if(i<n||j<m){
				flag=true;
				break;
			}
		}
		if(flag)puts("-1");
		else{
			for(ri i=1;i<=tp;++i)printf("%d ",st[i]);
			printf("\n");
		}
	}
	return 0;
}