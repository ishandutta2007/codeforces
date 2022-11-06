#include<bits/stdc++.h>
#define S 200009
#define N 410009
using namespace std;

int n,W,H,head[N],head2[N],pre[N],pre2[N],nxt[N],nxt2[N];
int last[N],last2[N];
struct node{ int x,y,z,id; }a[N],ans[N],ans2[N];
bool cmp(node u,node v){
	if (u.x!=v.x) return u.x<v.x;
	if (u.x==1) return u.y<v.y; else
		return u.y-u.z==v.y-v.z && u.y>v.y || u.y-u.z<v.y-v.z;
}
int main(){
	scanf("%d%d%d",&n,&W,&H);
	int i,j,k;
	for (i=1; i<=n; i++){
		scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	//for (i=1; i<=n; i++) cout<<a[i].x<<' '<<a[i].y<<' '<<a[i].z<<endl;
	for (i=1; i<=n; i++) if (a[i].x==2){
		if (!last[a[i].y-a[i].z+S]) head[a[i].y-a[i].z+S]=i;
		pre[i]=last[a[i].y-a[i].z+S];
		nxt[last[a[i].y-a[i].z+S]]=i;
		last[a[i].y-a[i].z+S]=i;
		//cout<<i<<endl;
	}
	for (i=1; i<=n; i++) if (a[i].x==1){
		if (!head[a[i].y-a[i].z+S]){
			//cout<<i<<endl;
			ans[i]=(node){a[i].y,H,0}; continue;
		}
		//cout<<a[i].y-a[i].z<<' '<<a[i].y<<' '<<head[a[i].y-a[i].z+S]<<endl;
		ans[head[a[i].y-a[i].z+S]]=(node){a[i].y,H,0};
		//cout<<"	"<<last[a[i].y-a[i].z+S]<<endl;
		nxt[last[a[i].y-a[i].z+S]]=i;
		pre[i]=last[a[i].y-a[i].z+S];
		last[a[i].y-a[i].z+S]=i;
		head[a[i].y-a[i].z+S]=nxt[head[a[i].y-a[i].z+S]];
	}
	for (i=1; i<=n; i++) if (a[i].x==2){
		if (!last2[a[i].y-a[i].z+S]) head2[a[i].y-a[i].z+S]=i;
		pre2[i]=last2[a[i].y-a[i].z+S];
		nxt2[last2[a[i].y-a[i].z+S]]=i;
		last2[a[i].y-a[i].z+S]=i;
	}
	for (i=1; i<=S+S; i++)
		for (j=head[i],k=head2[i]; j; j=nxt[j],k=nxt2[k]){
			ans[j]=(node){W,a[k].y,0};
			//cout<<"	"<<j<<' '<<k<<endl;
		}
	//for (i=1; i<=n; i++) cout<<ans[i].x<<' '<<ans[i].y<<endl;
	for (i=1; i<=n; i++) ans2[a[i].id]=ans[i];
	for (i=1; i<=n; i++) printf("%d %d\n",ans2[i].x,ans2[i].y);
	return 0;
}