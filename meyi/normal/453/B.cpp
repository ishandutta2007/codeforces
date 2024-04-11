#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=2e5+10,maxn=110;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
vector<int>pri;
bool vis[maxn];
inline void sieve(int siz){
	pri.clear();
	for(ri i=2;i<=siz;++i){
		if(!vis[i])pri.push_back(i);
		for(ri j:pri){
			if(i*j>siz)break;
			vis[i*j]=true;
			if(i%j==0)break;
		}
	}
}
int val[maxn];
inline void init(){
	for(ri i=2;i<59;++i)
		for(ri j=0;j<pri.size();++j)
			if(i%pri[j]==0)
				val[i]|=(1<<j);
}
int a[maxn],ans[maxn][maxm],f[maxn][maxm],m,n;
void print(int p,int k){
	if(!p)return;
	print(p-1,k^val[ans[p][k]]);
	printf("%d ",ans[p][k]);
}
signed main(){
	sieve(53);
	m=(1<<pri.size())-1;
	init();
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	memset(f,0x3f,sizeof f);
	f[0][m]=0;
	for(ri i=1;i<=n;++i)
		for(ri j=0;j<=m;++j)
			for(ri k=1;k<59;++k)
				if((j&val[k])==val[k]){
					ri tmp=f[i-1][j]+abs(a[i]-k);
					if(tmp<f[i][j^val[k]]){
						ans[i][j^val[k]]=k;
						f[i][j^val[k]]=tmp;
					}
				}
	ri pos=min_element(f[n],f[n]+m+1)-f[n];
	print(n,pos);
	return 0;
}