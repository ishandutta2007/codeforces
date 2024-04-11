#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1505;
int n,v[N<<1][2];ll ans;bool vst[N<<1];
void add(int x,int y){v[x][0]?v[x][1]=y:v[x][0]=y;}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=2*n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	for(int i=1;i<=n;i++)ans+=i*(n-i+1);ans*=n*(n+1);
	for(int i=1;i<=n<<1;i++){
		fill(vst,vst+(n<<1)+1,0);
		for(int j=1,l=i,r=i,mn0=n+1,mx0=0,mn1=n<<1|1,mx1=n;;j++){
			vst[l]=vst[r]=1;
			if(l<=n)mn0=min(mn0,min(l,r)),mx0=max(mx0,max(l,r));
			else mn1=min(mn1,min(l,r)),mx1=max(mx1,max(l,r));
			l=v[l][vst[v[l][0]]],r=v[r][!vst[v[r][1]]];
			if(j==1){
				if(i<=n)ans-=1ll*i*(n-i+1)*(n*(n+1)/2-(l-n)*(n*2-l+1)-(r-n)*(n*2-r+1)+(min(l,r)-n)*(2*n-max(l,r)+1));
				else ans-=1ll*(i-n)*(n*2-i+1)*(n*(n+1)/2-l*(n-l+1)-r*(n-r+1)+min(l,r)*(n-max(l,r)+1));
			}
			else{
				int a=min(l,r),b=max(l,r);
				if(l<=n){
					if(a<mn0&&b>mx0)ans-=1ll*(mn0-a)*(b-mx0)*(mn1-n)*(n*2-mx1+1);
					else if(b<mn0)ans-=1ll*(mn0-b)*(n-mx0+1)*(mn1-n)*(n*2-mx1+1);
					else if(a>mx0)ans-=1ll*mn0*(a-mx0)*(mn1-n)*(n*2-mx1+1);
				}
				else{
					if(a<mn1&&b>mx1)ans-=1ll*(mn1-a)*(b-mx1)*mn0*(n-mx0+1);
					else if(b<mn1)ans-=1ll*(mn1-b)*(n*2-mx1+1)*mn0*(n-mx0+1);
					else if(a>mx1)ans-=1ll*(mn1-n)*(a-mx1)*mn0*(n-mx0+1);
				}
			}
			if(l==r)break;
		}
	}
	printf("%lld\n",ans/2);
	return 0;
}