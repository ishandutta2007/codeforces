#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
bool vis[MAXN],lp[MAXN],q[MAXN];
int ans;
int t1[MAXN],t2[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=0;
		for(int i=1; i<=n; i++)
			vis[i]=lp[i]=b[i]=q[i]=0,scanf("%d",a+i);
		for(int i=1; i<=n; i++){
			if(vis[i]) continue;
			int p1=i,p2=i;
			do{
				if(vis[p1]||vis[p2]){
					p1=p2=0;
					break;
				}
				p1=a[p1];
				p2=a[a[p2]];
			}while(p1!=p2);
			if(p1){
				lp[p1]=1;
				do{
					p1=a[p1];
					lp[p1]=1;
				}while(p1!=p2);
			}
			p1=i;
			while(!vis[p1]){
				vis[p1]=1;
				p1=a[p1];
			}
		}
		//for(int i=1; i<=n; i++) printf("%d vis %d lp %d\n",i,vis[i],lp[i]);
		for(int i=1; i<=n; i++)
			if(!lp[i]&&!q[a[i]]) q[b[i]=a[i]]=1,ans++;
		for(int i=1; i<=n; i++)
			if(lp[i]&&!q[a[i]]) q[b[i]=a[i]]=1,ans++;
		*t1=*t2=0;
		for(int i=1; i<=n; i++){
			if(!b[i]) t1[++*t1]=i;
			if(!q[i]) t2[++*t2]=i;
		}
		for(int i=1,l=1,r=*t1,x=0,y=0; i<=*t1; i++){
			if(t1[i]!=t2[l]) y=b[x=t1[i]]=t2[l++];
			else if(t1[i]!=t2[r]) y=b[x=t1[i]]=t2[r--];
			else{
				b[t1[i]]=y;
				b[x]=t2[l];
			}
		}
		printf("%d\n",ans);
		for(int i=1; i<=n; i++)
			printf("%d ",b[i]);
		puts("");
	}
	return 0;
}