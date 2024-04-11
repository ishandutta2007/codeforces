//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define foor(i,a,b) for (int i=(a);i<=(b);i++)
#define door(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define IOS ios::sync_with_stdio(false)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
multiset<int>S,S1;
int ans;
int zw[2];
int n,q,a[N],b[N],c[N];
void ins(int x)
{
//	cout<<x<<endl;
	if (S.size()==0)
	{
		S.insert(x);
		return;
	}
	auto it=S.lower_bound(x);
	if (it!=S.end())
	{
		S1.insert(x-(*it));
	}
//	cout<<x<<endl;
	if (it!=S.begin())
	{
//		cout<<x<<endl;
		auto it1=it;
		--it;
		if (it1!=S.end()) S1.erase(S1.find((*it)-(*it1)));
//		cout<<x<<endl;
		S1.insert((*it)-x);
	}
	S.insert(x);
}
void del(int x)
{
//	cout<<"!!!"<<x<<" "<<S.count(x)<<endl;
	auto it=S.find(x);
	if (S.size()==1) 
		S.erase(it);
	else
	{
//		cout<<"!1"<<x<<endl;
	if (it!=S.begin()&&it!=(--S.end()))
	{
		auto it1=it;
		it1--;
		auto it2=it;
		it2++;
		if (it2!=S.end())
			S1.insert((*(it1))-(*(it2)));
	}
	if (it!=S.begin())
	{
//		cout<<"!2"<<x<<endl;
		auto it1=it;
		it1--;
		S1.erase(S1.find((*it1)-(*it)));
	}
	if (it!=(S.end()))
	{
//		cout<<"!3"<<x<<endl;
		auto it1=it;
		it1++;
		if (it1!=S.end())
		S1.erase(S1.find((*it)-(*it1)));
	}
	S.erase(it);
	}
}
signed main()
{
	n=read();q=read();
	for (int i=1;i<=n;i++) a[i]=read(),ins(a[i]);
//	cout<<"???"<<(*S.rbegin())<<" "<<(*S.begin())<<endl;
	writeln((*S1.begin())+(*S.rbegin())-(*S.begin()));
	for (int i=1;i<=q;i++)
	{
		b[i]=read(),c[i]=read();
		if (b[i]==0) del(c[i]);
		else ins(c[i]);
		if (S.size()==0) writeln(0);
		else writeln((*S1.begin())+(*S.rbegin())-(*S.begin()));
//		cout<<S.size()<<" "<<S1.size()<<endl;
	}
}
/*

*/