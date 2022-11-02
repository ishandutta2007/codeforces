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
#define int long long
const int maxn=1e5+5,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,u,v;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	u=read(),v=read();int x=v-u;
	if(x%2==1||u>v){puts("-1");}
	else if(u==v&&!u){puts("0");}
	else if(u==v){cout<<1<<"\n"<<u<<endl;}
	else if((u&(x/2))==0){
		cout<<2<<endl;
		cout<<x/2<<" "<<(u^(x/2));
	}else{
		cout<<3<<endl;
		cout<<u<<" "<<x/2<<" "<<x/2<<endl;
	}
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-05-10 21:38
*********************************************************************/