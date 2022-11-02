#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit(x) (x&-x)
const int maxn=500+5,M=34005;
inline int read(){
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x){
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,k,a[maxn][maxn],c[maxn*maxn],r[maxn][maxn],num;
void add(int x){c[x]++;if(c[x]==1)num++;}
void del(int x){c[x]--;if(c[x]==0)num--;}
void check(){if(num==k||num==k-1)puts("1"),exit(0);}
signed main(){
	//freopen("1.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			a[i][j]=read();add(a[i][j]);
		}
	if(num<=k)printf("%d\n",k-num),exit(0);
	for(int i=1;i<=n;i++){
		r[i][1]=1;del(a[i][1]);
		for(int j=1;j<=n;j++){
			//cout<<i<<" "<<j<<" "<<r[i][j]-j+1<<endl;
			check();
			while(num>k&&r[i][j]<n){
				r[i][j]++;int len=r[i][j]-j+1;
				if(i+len-1>n){r[i][j]--;break;}
				for(int l=i;l<=i+len-1;l++)del(a[l][r[i][j]]);
				for(int l=j;l<r[i][j];l++)del(a[i+len-1][l]);
				check();
			}
			r[i][j+1]=r[i][j];
			int len=r[i][j]-j+1;
			for(int l=i;l<=i+len-1;l++)add(a[l][j]);
			for(int l=j+1;l<=r[i][j];l++)add(a[i+len-1][l]);
		}
		add(a[i][n]);
	}puts("2");
 	return 0;
}