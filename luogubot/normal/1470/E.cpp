#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool ST;
const int N=3e4+10,M=5;
int n,c,m,p[N],L[M][N],R[M][N];
struct node{
	int l,r,w;
	bool operator < (const node &x){
		return p[r]<p[x.r];
	}
}q[M][N*M*2];
int C(int n,int m){
	if(!m)return 1;
	if(n<=0||m<0||n<m)return 0;
	int ans=n;Rof(i,n-1,n-m+1)ans*=i;
	For(i,2,m)ans/=i;
	return ans;
}
int way(int n,int c){
	int all=0;For(i,0,c)all+=C(n-1,i);
//	printf("ways(%d,%d) = %d\n",n,c,all);
	return all;
}
node tol[10],tor[10],tl,tr;
void work(node* q,int* L,int* R,int c){
	int l=N*M,r=l;q[r]=(node){n,n,1};
	Rof(i,n,1){
		For(j,1,min(c,n-i)){
			node t=(node){i,i+j,way(n-(i+j),c-j)};
			if(p[i+j]<p[i])q[--l]=t;
			else q[++r]=t;
		}L[i]=l,R[i]=r;
		if(i<n){
			if(l<L[i+1])sort(q+l,q+L[i+1]);
			if(r>R[i+1])sort(q+R[i+1]+1,q+r+1);
		}
	}q[l-1].w=0;For(i,l+1,r)q[i].w+=q[i-1].w;
//	if(c==1)For(i,l,r)printf("[%d,%d] {%d}\n",q[i].l,q[i].r,q[i].w);
}
node F(int i,int c,int k,node* q){
	int l=L[c][i],r=R[c][i],del=q[l-1].w;
	assert(q[r].w-del>=k); 
//	cout<<q[r].w-del<<">="<<k<<endl;
	while(l<=r){
		int mid=l+r>>1;
		if(q[mid].w-del>=k)r=mid-1;
		else l=mid+1;
	}
//	printf("ok find [%d] in [%d,%d]\n",r,L[c][i],R[c][i]); 
	node ret=q[r+1];ret.w=q[r].w-del;
	return ret;
}
node stk[10];int tp;
bool ED;
signed main(){
//	printf("%.2lf MB\n",abs(&ED-&ST)/1024.0/1024.0);
	int T=read();while(T--){
		n=read(),c=read(),m=read();For(i,1,n)p[i]=read();
		int all=way(n,c);For(i,1,c)work(q[i],L[i],R[i],i);
		while(m--){
			int pos=read(),rk=read(),rst=c,i=1;
			if(rk>all){puts("-1");continue;}
			while(rst&&rk&&i<=n){
				node tmp=F(i,rst,rk,q[rst]);
				assert(tmp.w<rk);
				stk[++tp]=tmp,i=tmp.r+1,rst-=tmp.r-tmp.l,rk-=tmp.w;
//				printf("[%d,%d]\n",tmp.l,tmp.r);
			}For(i,1,tp)reverse(p+stk[i].l,p+stk[i].r+1);
			printf("%lld\n",p[pos]);
			For(i,1,tp)reverse(p+stk[i].l,p+stk[i].r+1);tp=0;
		}
	}
	return 0;
}//fasdsa