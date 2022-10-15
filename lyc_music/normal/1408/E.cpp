//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define int long long

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

int n,m,a[500005],b[500005],p,tp,tot,now,now1,dis,now2,ans,f[500005];

vector<int>p1[500005];

pair<int,int>c[500005];

bool Cmp(pair<int,int> x,pair<int,int>y)
{
	return a[x.first]+b[x.second]>a[y.first]+b[y.second];
}

int gf(int k)
{
	return (f[k]==k)?k:(f[k]=gf(f[k]));
}

void merge(int x,int y)
{
	f[f[x]]=f[y];
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=m;i++) b[i]=read(),f[i]=i;
	for (int i=1;i<=n;i++)
	{
		p=read();
		for (int j=1;j<=p;j++)
		  tp=read(),tot++,c[tot]=make_pair(i,tp);
	}
	sort(c+1,c+tot+1,Cmp);
	for (int i=1;i<=tot;i++)
	{
		now=c[i].first,now1=c[i].second;
		dis=a[now]+b[now1];
		//cout<<now<<" "<<now1<<" "<<dis<<" "<<gf(1)<<" "<<gf(2)<<endl;
		if (p1[now].size()>0)
		{
			now2=p1[now][p1[now].size()-1];
			if (gf(now2)==gf(now1))
			{
				ans+=dis;
			} else
			{
				merge(now2,now1);
				p1[now].push_back(now1);
			}
		} else p1[now].push_back(now1);
	}
	writeln(ans);
}