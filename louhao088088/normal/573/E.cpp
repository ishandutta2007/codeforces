// Problem: CF573E Bear and Bowling
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF573E
// Memory Limit: 250 MB
// Time Limit: 6000 ms
// 2022-01-20 14:13:21
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define lowbit (x&-x)
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
mt19937 rnd(time(0));
int n,m,a[maxn],b[maxn],tag[maxn],ls[maxn],tag2[maxn],rs[maxn],sum[maxn],v[maxn],s[maxn],w[maxn],tot=0,Rt,ans=0;
void get(int rt,int x,int k){if(!rt)return;tag[rt]+=x,tag2[rt]+=k;sum[rt]+=(x+x+s[rt]*k-k)*s[rt];v[rt]+=x+s[ls[rt]]*k;}
int ins(int x){int rt=++tot;v[rt]=sum[rt]=x;w[rt]=rnd();ls[rt]=rs[rt]=tag[rt]=tag2[rt]=0;s[rt]=1;return tot;}
void push(int rt){if(tag[rt]||tag2[rt]){get(ls[rt],tag[rt],tag2[rt]),
get(rs[rt],tag[rt]+tag2[rt]*(s[ls[rt]]+1),tag2[rt]);tag[rt]=0,tag2[rt]=0;}}
void pushup(int rt){s[rt]=s[ls[rt]]+s[rs[rt]]+1;sum[rt]=sum[ls[rt]]+sum[rs[rt]]+v[rt];}
int merge(int x,int y)
{
	if(!x||!y)return x+y;
	if(w[x]>w[y]){push(x);rs[x]=merge(rs[x],y);pushup(x);return x;}
	push(y),ls[y]=merge(x,ls[y]);pushup(y);return y;
}
void split(int rt,int &a,int &b,int k)
{
	if(!rt){a=0,b=0;return;}push(rt);
	if(s[ls[rt]]>=k)b=rt,split(ls[b],a,ls[b],k);
	else a=rt,split(rs[a],rs[a],b,k-s[ls[rt]]-1);pushup(rt);
}
void add(int l,int r,int x,int k)
{
	int a,b,c;//cout<<Rt<<endl;
	split(Rt,a,b,l-1);//cout<<b<<endl;
	split(b,b,c,r-l+1);get(b,x,k);
	Rt=merge(merge(a,b),c);
}
int getx(int x)
{
	if(x==0)return 0;
	int a,b,c,d;split(Rt,a,b,x-1);split(b,b,c,1);d=v[b];
	Rt=merge(merge(a,b),c);return d;
}
bool check(int x,int y){if(getx(x-1)+x*y>=getx(x))return 1;return 0;}
int getsum(int l,int r)
{
	int res=r+1;int h=r+1;//cout<<a[h]<<endl;
	while(l<=r)
	{
		
		int mid=l+r>>1;
		//cout<<l<<" "<<r<<" "<<getx(mid-1)+mid*a[h]<<" "<<getx(mid)<<endl;
		if(check(mid,a[h]))res=mid,r=mid-1;
		else l=mid+1;
	}return res;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();int g=0;
	for(int i=1;i<=n;i++)
	{
		//g=g+i*a[i];cout<<g<<endl;
		//Rt=merge(Rt,ins(g));
		int z=getsum(1,i-1);
		//cout<<z<<" "<<getx(z-1)+z*a[i]<<" "<<getx(z)<<endl;
		//if(z==0)z=1;
		int gg=getx(z-1);
		int b,c;
		split(Rt,b,c,z-1);Rt=merge(b,merge(ins(gg),c));//cout<<z*a[i]<<endl;
		add(z,i,z*a[i],a[i]);//cout<<getx(z)<<endl;
		//cout<<z*a[i]<<endl;
		//for(int j=1;j<=i;j++)cout<<getx(j)<<" ";cout<<endl<<endl;
	}
	for(int i=1;i<=n;i++)ans=max(ans,getx(i));
	cout<<ans;
 	return 0;
}
/*
1 2 0
2 

1 5 2
5 12 

3 6 0
5 12 6 

3 18 6
5 12 18 14 

5 -1 0
5 12 18 14 -1 

5 4 -1
5 12 18 14 4 -13 

3 21 18
5 12 21 30 29 22 -13 

1 5 5
5 15 27 41 55 59 57 27 

9 -18 0
5 15 27 41 55 59 57 27 -18 

8 41 27
5 15 27 41 55 59 57 41 9 -38 

59

*/