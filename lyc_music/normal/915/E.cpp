//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define N 15001000
using namespace std;

inline int read(){
    int x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writesp(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
    printf(" ");
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}

int sum[N],lz[N],lson[N],rson[N],n,q,x,y,p,cnt,rt;

void pushup(int k)
{
	sum[k]=sum[lson[k]]+sum[rson[k]];
}

void pushdown(int k,int l,int r)
{
	if (lz[k]==-1) return;
	if (!lson[k]) lson[k]=++cnt;
	if (!rson[k]) rson[k]=++cnt;
	sum[lson[k]]=(l+(r-l)/2-l+1)*lz[k];
	sum[rson[k]]=(r-(l+(r-l)/2+1)+1)*lz[k];
	lz[lson[k]]=lz[k];
	lz[rson[k]]=lz[k];
	lz[k]=-1;
}

void update(int &rt,int l,int r,int l1,int r1,int val)
{
	//cout<<rt<<" "<<l<<" "<<r<<" "<<l1<<" "<<r1<<endl;
	if (l>r) return;
	if (!rt) rt=++cnt;
	if (l>=l1&&r<=r1)
	{
		sum[rt]=(r-l+1)*val;
		lz[rt]=val;
		return;
	}
	pushdown(rt,l,r);
	if (l1<=l+(r-l)/2) update(lson[rt],l,l+(r-l)/2,l1,r1,val);
	if (r1>l+(r-l)/2) update(rson[rt],l+(r-l)/2+1,r,l1,r1,val);
	pushup(rt);
}

signed main()
{
    n=read(),q=read();
    update(rt,1,n,1,n,0);
	for (int i=1;i<=q;i++)
	{
		x=read(),y=read(),p=read();
		update(rt,1,n,x,y,2-p);
		writeln(n-sum[1]);
	}
}