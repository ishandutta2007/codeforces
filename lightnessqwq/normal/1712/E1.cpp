#include<stdio.h>
#include<algorithm>
#include<vector>
#include<assert.h>
using namespace std;
const int maxn=200005,B=450;
int n,m,bt,x,y;
int bl[maxn],br[maxn],bel[maxn];
long long now;
long long ans[maxn];
struct question{
    int x,y,id;
}q[maxn];
inline int cmp(question a,question b){
    return bel[a.x]!=bel[b.x]? a.x<b.x:a.y<b.y;
}
vector<int>v[maxn],up[maxn];
vector<long long>f[maxn];
void init(int n){
	for(int i=1;i<=n;i++)
		for(int j=i+i;j<=n;j+=i)
			v[j].emplace_back(i);
	for(int i=1;i<=n;i++){
		up[i].push_back(i),f[i].push_back(0);
		for(int j=i+i;j<=n;j+=i){
			up[i].emplace_back(j);
			int p=upper_bound(v[j].begin(),v[j].end(),i)-v[j].begin();
			f[i].emplace_back(f[i].back()+(v[j].size()-p));
		}
	}
}
void lupd(int x,int y,int w){
	int p=upper_bound(up[x].begin(),up[x].end(),y)-up[x].begin();
	assert(p>=1);
//	printf("lft p=%d x=%d y=%d w=%d f=%lld\n",p,x,y,w,f[x][p-1]);
	now+=w*f[x][p-1];
	//lcm=k
	if(x*2<=y&&x%3==0)//k/2 2k/3 k
		now+=w;
	if(x%2==0&&x/2*5<=y&&x%3==0)//2k/5 2k/3 k
		now+=w;
	//lcm=2k
}
void rupd(int x,int y,int w){
	int p=lower_bound(v[y].begin(),v[y].end(),x)-v[y].begin();
	int t=v[y].size()-p;
//	printf("rgt p=%d x=%d y=%d w=%d t=%d\n",p,x,y,w,t);
	now+=1ll*t*(t-1)/2*w;
	//lcm=k
	if(y%3==0&&y%2==0&&y/2>=x)
		now+=w;
	if(y%3==0&&y%5==0&&y/5*2>=x)
		now+=w;
	//lcm=2k
}
int main(){
    n=200000,scanf("%d",&m),bt=m/B,init(n);
    for(int i=1;i<=bt;i++)
        bl[i]=br[i-1]+1,br[i]=i*B;
    if(br[bt]<n)
        bt++,bl[bt]=br[bt-1]+1,br[bt]=n;
    for(int i=1;i<=bt;i++)
        for(int j=bl[i];j<=br[i];j++)
            bel[j]=i;
    for(int i=1,l,r;i<=m;i++)
		scanf("%d%d",&l,&r),ans[i]=1ll*(r-l+1)*(r-l)*(r-l-1)/6,q[i]=question{l,r,i};
    sort(q+1,q+1+m,cmp);
    x=1,y=0,now=0;
    for(int i=1;i<=m;i++){
        int qx=q[i].x,qy=q[i].y,qi=q[i].id;
        if(qx==qy)
            continue;
        while(x>qx)
            x--,lupd(x,y,1);
        while(y<qy)
            y++,rupd(x,y,1);
        while(x<qx)
        	lupd(x,y,-1),x++;
        while(y>qy)
            rupd(x,y,-1),y--;
//      printf("qi=%d now=%lld\n",qi,now);
        ans[qi]-=now;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    return 0;
}//test