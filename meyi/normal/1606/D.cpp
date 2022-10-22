#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=5e5+10;
vector<int>a[maxn],pre_mn[maxn],pre_mx[maxn],suf_mn[maxn],suf_mx[maxn];
int ans[maxn],dw_mn[maxn],dw_mx[maxn],id[maxn],m,n,t_case;
int main(){
    scanf("%d",&t_case);
    while(t_case--){
        scanf("%d%d",&n,&m);
        for(ri i=1;i<=n;++i){
			a[i].resize(m+1);
			ans[i]=0;
			id[i]=i;
			pre_mn[i].resize(m+1);
			pre_mx[i].resize(m+1);
			pre_mn[i][0]=INT_MAX;
			pre_mx[i][0]=INT_MIN;
			for(ri j=1;j<=m;++j){
				scanf("%d",&a[i][j]); 
				pre_mn[i][j]=min(pre_mn[i][j-1],a[i][j]);
				pre_mx[i][j]=max(pre_mx[i][j-1],a[i][j]);
			}
		}
		for(ri i=1;i<=n;++i){
			suf_mn[i].resize(m+1);
			suf_mx[i].resize(m+1);
			suf_mn[i][m]=a[i][m];
			suf_mx[i][m]=a[i][m];
			for(ri j=m-1;j;--j){
				suf_mn[i][j]=min(suf_mn[i][j+1],a[i][j]);
				suf_mx[i][j]=max(suf_mx[i][j+1],a[i][j]);
			}
		}
		for(ri i=1;i<m;++i){
			if(i==1)sort(id+1,id+n+1,[&](const int &x,const int &y){return pre_mn[x][i]>pre_mn[y][i];});
			dw_mn[n+1]=INT_MAX,dw_mx[n+1]=INT_MIN;
			for(ri k=n;k;--k){
				ri j=id[k];
				dw_mn[k]=min(dw_mn[k+1],suf_mn[j][i+1]);
				dw_mx[k]=max(dw_mx[k+1],pre_mx[j][i]);
			}
			ri up_mn=INT_MAX,up_mx=INT_MIN;
			for(ri k=1;k<n;++k){
				ri j=id[k];
				ckmin(up_mn,pre_mn[j][i]);
				ckmax(up_mx,suf_mx[j][i+1]);
				if(up_mn>dw_mx[k+1]&&up_mx<dw_mn[k+1]){
					puts("YES");
					for(ri l=1;l<=k;++l)ans[id[l]]=1;
					for(ri l=1;l<=n;++l)putchar(ans[l]?'R':'B');
					printf(" %d\n",i);
					goto skip;
				}
			}
		}
		puts("NO");
		skip:;
    }
    return 0;
}