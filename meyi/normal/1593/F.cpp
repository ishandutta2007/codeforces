#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=41;
struct node{
	int a,b,c,d;
};
node pre[maxn][maxn][maxn][maxn<<1];
int A,B,m,n,t_case;
char s[maxn];
void print(node k){
	if(!k.a)return;
	node tmp=pre[k.a][k.b][k.c][k.d];
	print({tmp.a%(n+1),tmp.b,tmp.c,tmp.d});
	putchar(k.d==tmp.d+1?'R':'B');
}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d%s",&n,&A,&B,s+1);
		m=n<<1;
		for(ri i=0;i<=n;++i)
			for(ri j=0;j<A;++j)
				for(ri k=0;k<B;++k)
					for(ri l=0;l<=m;++l)
						pre[i][j][k][l].a=n+1;
		pre[0][0][0][n].a=0;
		for(ri i=1;i<=n;++i){
			s[i]^=48;
			for(ri j=0;j<A;++j)
				for(ri k=0;k<B;++k)
					for(ri l=1;l<m;++l)
						if(pre[i-1][j][k][l].a<i){
							pre[i][(j*10+s[i])%A][k][l+1]={i-1,j,k,l};
							pre[i][j][(k*10+s[i])%B][l-1]={i-1,j,k,l};
						}
		}
		for(ri i=0;i<n;++i){
			if(pre[n][0][0][n-i].a<n){
				print({n,0,0,n-i}),putchar(10);
				goto skip;
			}
			if(pre[n][0][0][n+i].a<n){
				print({n,0,0,n+i}),putchar(10);
				goto skip;
			}
		}
		puts("-1");
		skip:;
	}
	return 0;
}