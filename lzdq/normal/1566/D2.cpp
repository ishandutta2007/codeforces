#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=305;
int n,m,a[MAXN*MAXN],s[MAXN*MAXN],b[MAXN*MAXN];
int rsum[MAXN][MAXN];
vector<int> vec[MAXN*MAXN];
inline void Add(int *s,int x){
	for(int i=x; i<=m; i+=i&-i)
		s[i]++;
}
inline int Query(int *s,int x){
	int res=0;
	for(int i=x; i; i-=i&-i)
		res+=s[i];
	return res;
}
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n*m; i++)
			scanf("%d",a+i),b[i]=a[i],vec[i].clear();
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				rsum[i][j]=0;
		sort(b+1,b+n*m+1);
		*b=unique(b+1,b+n*m+1)-b-1;
		for(int i=1; i<=n*m; i++)
			vec[lower_bound(b+1,b+*b+1,a[i])-b].push_back(i);
		int ans=0;
		for(int i=1,k=0; i<=*b; i++){
			sort(vec[i].begin(),vec[i].end());
			int l=k+1,r=k+vec[i].size();
			if((l+m-1)/m!=(r+m-1)/m){
				int x=(l+m-1)/m,y=(r+m-1)/m;
				//printf("x %d y %d\n",x,y);
				for(int j=x*m-l; j>=0; j--) s[vec[i][j]]=++k;
				int cnt=x*m-l;
				for(int t=x+1; t<y; t++,cnt+=m)
					for(int j=m; j; j--)
						s[vec[i][j+cnt]]=++k;
				for(int j=r-(y-1)*m; j; j--)
					s[vec[i][j+cnt]]=++k;//,printf("j %d j+cnt %d\n",j,j+cnt);
			}else for(int j=vec[i].size()-1; j>=0; j--)
				s[vec[i][j]]=++k;
		}
		for(int i=1; i<=n*m; i++){
			//printf("%d s %d\n",i,s[i]);
			int x=(s[i]+m-1)/m,y=(s[i]-1)%m+1;
			ans+=Query(rsum[x],y);
			Add(rsum[x],y);
		}
		printf("%d\n",ans);
	}
	return 0;
}