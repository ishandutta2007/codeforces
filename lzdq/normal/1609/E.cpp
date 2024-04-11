#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,INF=0x3fffffff;
int n,q;
char s[MAXN];
struct Matrix{
	int a[3][3];
	int* operator [](int x){
		return a[x];
	}
}idm,mt[3],a[MAXN<<2];
Matrix operator *(Matrix a,Matrix b){
	static Matrix c;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++){
			c[i][j]=INF;
			for(int k=0; k<3; k++)
				c[i][j]=min(c[i][j],a[i][k]+b[k][j]);
		}
	return c;
}
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
inline void pushup(int k){
	a[k]=a[lc]*a[rc];
}
void Build(int k,int l,int r){
	if(l==r){
		a[k]=mt[s[l]-'a'];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int k,int l,int r,int w){
	if(l==r){
		a[k]=mt[s[l]-'a'];
		return ;
	}
	int mid=l+r>>1;
	if(w<=mid) Modify(ls,w);
	else Modify(rs,w);
	pushup(k);
	return ;
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	idm[1][0]=idm[2][0]=idm[2][1]=INF;
	for(int i=0; i<3; i++){
		mt[i]=idm;
		mt[i][i][i]=1;
	}
	Build(1,1,n);
	while(q--){
		int pos;
		char c[3];
		scanf("%d%s",&pos,c);
		s[pos]=*c;
		Modify(1,1,n,pos);
		printf("%d\n",a[1][0][2]);
	}
	return 0;
}