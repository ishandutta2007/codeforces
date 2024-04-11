#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=32;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],ans[maxn][maxn],b[maxn],k,n,sx,sy;
int main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<n;++i){
		a[i-1]=(i&-i)*(i&-i);
		b[i-1]=a[i-1]<<1;
	}
	for(ri i=0;i<n;++i,printf("\n"))
		for(ri j=0;j<n-1;++j)
			printf("%d ",a[j]);
	for(ri i=0;i<n-1;++i,printf("\n"))
		for(ri j=0;j<n;++j)
			printf("%d ",b[i]);
	fflush(stdout);
	while(k--){
		ri x;
		scanf("%d",&x);
		for(ri i=0;i<n;++i)memset(ans[i],-1,n<<2);
		ans[sx][sy]=0;
		typedef pair<int,int> pii;
		#define fi first
		#define se second
		queue<pii>q;
		q.emplace(sx,sy);
		while(q.size()){
			ri nx=q.front().fi,ny=q.front().se;q.pop();
			if(ans[nx][ny]==x){
				printf("%d %d\n",nx+1,ny+1);
				fflush(stdout);
				sx=nx,sy=ny;
				break;
			}
			if(nx>0&&ans[nx-1][ny]==-1)ans[nx-1][ny]=ans[nx][ny]^b[nx-1],q.emplace(nx-1,ny);
			if(ny>0&&ans[nx][ny-1]==-1)ans[nx][ny-1]=ans[nx][ny]^a[ny-1],q.emplace(nx,ny-1);
			if(nx<n-1&&ans[nx+1][ny]==-1)ans[nx+1][ny]=ans[nx][ny]^b[nx],q.emplace(nx+1,ny);
			if(ny<n-1&&ans[nx][ny+1]==-1)ans[nx][ny+1]=ans[nx][ny]^a[ny],q.emplace(nx,ny+1);
		}
	}
	return 0;
}