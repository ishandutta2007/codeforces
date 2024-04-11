//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,ans,l[N],r[N],n;
int s[N];
int s1[N];
int L[N],R[N];
vector<int>g;
int m;
signed main()
{
	T=read();
	while (T--)
	{
		g.clear();
		n=read();
		ans=n;
		for (int i=1;i<=n;i++)
		{
			l[i]=read(),r[i]=read();
			 g.push_back(l[i]),g.push_back(r[i]),g.push_back(l[i]-1),g.push_back(r[i]+1);
		}
		sort(g.begin(),g.end());
		g.erase(unique(g.begin(),g.end()),g.end());
		for (int i=1;i<=n;i++)
			L[i]=lower_bound(g.begin(),g.end(),l[i]-1)-g.begin()+1,R[i]=lower_bound(g.begin(),g.end(),r[i]+1)-g.begin()+1,
			
			l[i]=lower_bound(g.begin(),g.end(),l[i])-g.begin()+1,r[i]=lower_bound(g.begin(),g.end(),r[i])-g.begin()+1;
		m=g.size();
		for (int i=1;i<=n;i++) s[R[i]]++,s1[L[i]]++;
		for (int i=1;i<=m;i++)
		{
			s[i]+=s[i-1];
		}
		for (int i=m;i>=1;i--) s1[i]+=s1[i+1];
//		cout<<"?"<<ans<<endl;
		for (int i=1;i<=n;i++)
		{
			ans=min(ans,s[l[i]]+s1[r[i]]);
//			cout<<"?"<<s[l[i]]+s1[r[i]]<<" "<<L[i]<<" "<<R[i]<<" "<<l[i]<<" "<<r[i]<<endl;
		}
		writeln(ans);
		for (int i=1;i<=m+2;i++) s[i]=s1[i]=0;
	}
}
/*
57334
1
2
3 3
8 8
4
1 3
4 4
5 7
6 7
3
1 4
2 7
5 7
4
1 7
2 3
2 4
4 8
6
2 4
2 7
3 5
3 6
6 6
6 7
2
1 7
4 7
2
1 2
5 6
4
2 4
3 8
4 4
7 8
2
1 5
2 8
5
1 5
2 4
3 5
3 8
4 8
3
2 3
4 6
5 8
6
1 5
2 8
3 6
4 6
7 7
7 8
4
2 3
2 4
5 6
7 8
2
1 1
2 4
2
3 8
8 8
5
2 3
4 4
4 7
6 8
7 8
3
1 2
4 5
4 8
2
3 3
8 8
1
1 5
4
2 4
3 5
5 6
6 6
5
1 3
2 2
4 6
6 6
8 8
6
1 3
2 2
2 6
2 7
3 4
6 7
*/