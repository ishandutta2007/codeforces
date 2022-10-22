#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=4e5+10,maxn=20;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int ans,ex[maxn][maxm],f[1<<maxn][2],m,mn[maxn],n,sum[1<<maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
char s[maxm];
inline pii calc(int x,int y){
	if(sum[x]<0)return {0,1};
	return {ex[y][sum[x]],sum[x]+mn[y]<0};
}
signed main(){
	scanf("%d",&n);
	for(ri i=0;i<n;++i){
		scanf("%s",s+1);
		m=strlen(s+1);
		for(ri j=1,k=1<<i;j<=m;++j){
			if(s[j]=='(')++sum[k];
			else --sum[k];
			if(sum[k]<=mn[i])mn[i]=sum[k],++ex[i][-mn[i]];
			s[j]=0;
		}
	}
	memset(f,-0x3f,sizeof f);
	f[0][0]=0;
	ri all=(1<<n)-1;
	for(ri i=0;i<=all;++i){
		if(i&(i-1))sum[i]=sum[i^(i&-i)]+sum[i&-i];
		for(ri j=0;j<n;++j)
			if(!(i&(1<<j))){
				ri k=i|(1<<j);
				ckmax(f[k][1],f[i][1]);
				pii it=calc(i,j);
				ckmax(f[k][it.se],f[i][0]+it.fi);
			}
	}
	printf("%d",max(f[all][0],f[all][1]));
	return 0;
}