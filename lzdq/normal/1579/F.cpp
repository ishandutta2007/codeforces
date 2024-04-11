#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
int gcd(int a,int b){
	if(!b) return a;
	return gcd(b,a%b);
}
int n,d,g,ans,m;
int a[MAXN],b[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&d);
		g=gcd(n,d);
		m=n/g;
		for(int i=0; i<n; i++)
			scanf("%d",a+i);
		ans=0;
		for(int i=0; i<g; i++){
			for(int j=0; j<m; j++)
				b[j]=a[i+g*j];
			//for(int j=0; j<m; j++) printf("%d ",a[j]); puts("");
			int w=0;
			for(int j=0,k=0; j<m; j++,k=(k+d/g)%m){
				if(b[k]) ans=max(ans,++w);
				else w=0;
			}
			if(w==m){
				ans=-1;
				break;
			}
			for(int j=0,k=0; j<m; j++,k=(k+d/g)%m){
				if(b[k]) ans=max(ans,++w);
				else break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}