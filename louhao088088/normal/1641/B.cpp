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
const int maxn=2e5+5,M=34005;
#define int long long
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
int T,n,x,num,pos;
map<int,int>s;
vector<int>a,Ans;
vector<pi>ans;
void solve()
{
	n=read();pos=1;s.clear();Ans.clear(),ans.clear(),a.clear();
	for(int i=1,x;i<=n;i++)x=read(),a.pb(x),s[x]++;
	for(auto i:s)if(i.se&1){puts("-1");return;}
	while(a.size()>0)
	{
		int i=1;while(a[i]!=a[0])i++;vector<int>tmp;
		for(int j=1;j<i;j++)tmp.pb(a[j]),ans.pb(mp(pos+i+j-1,a[j]));
		pos+=2*i;Ans.pb(2*i);reverse(tmp.begin(),tmp.end());
		for(int j=i+1;j<a.size();j++)tmp.pb(a[j]);a.swap(tmp);
	}
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d %d\n",i.fi,i.se);
	printf("%d\n",Ans.size());
	for(auto i:Ans)printf("%d ",i);puts("");
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	T=read();
	while(T--)
		solve();
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2022-02-23 18:10
*********************************************************************/