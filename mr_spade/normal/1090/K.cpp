#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
#include<map>
#define mp make_pair
#define fi first
#define se second
using std::pair;
using std::mp;
using std::vector;
using std::map;
const int mod1=1e9+7,mod2=1e9+9;
inline int add(int a,int b,int mod)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b,int mod)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b,int mod)
{
	return (long long)a*b%mod;
}
struct hash_t
{
	int h1,h2;
	hash_t(int x=0)
	{
		h1=h2=x;
		return;
	}
	inline bool operator<(const hash_t &th) const
	{
		if(h1!=th.h1)
			return h1<th.h1;
		return h2<th.h2;
	}
	inline bool operator==(const hash_t &th) const
	{
		return h1==th.h1&&h2==th.h2;
	}
	inline hash_t operator+(const hash_t &th)
	{
		hash_t res;
		res.h1=add(h1,th.h1,mod1);
		res.h2=add(h2,th.h2,mod2);
		return res;
	}
	inline hash_t operator-(const hash_t &th)
	{
		hash_t res;
		res.h1=sub(h1,th.h1,mod1);
		res.h2=sub(h2,th.h2,mod2);
		return res;
	}
	inline hash_t operator*(const hash_t &th)
	{
		hash_t res;
		res.h1=mul(h1,th.h1,mod1);
		res.h2=mul(h2,th.h2,mod2);
		return res;
	}
};
const int base=31;
const int N=1e5+5;
int n;
int sl,tl;
int dis[N];
char s[N],t[N];
int k1[N];
hash_t k2[N];
vector<int> V[N];
map<pair<int,hash_t>,int> M;
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void merge(int x,int y)
{
	dis[find(x)]=find(y);
}
signed main()
{
	map<pair<int,hash_t>,int>::iterator it;
	register int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",s+1,t+1);
		sl=strlen(s+1);
		tl=strlen(t+1);
		for(j=1;j<=tl;j++)
			k1[i]|=1<<(t[j]-'a');
		while(sl>0&&(k1[i]>>(s[sl]-'a')&1))
			sl--;
		for(j=1;j<=sl;j++)
			k2[i]=k2[i]*base+s[j]-'a'+1;
		dis[i]=i;
		if((it=M.find(mp(k1[i],k2[i])))!=M.end())
			merge(it->se,i);
		else
			M[mp(k1[i],k2[i])]=i;
	}
	int cnt=0;
	for(i=1;i<=n;i++)
	{
		if(dis[i]==i)
			cnt++;
		V[find(i)].push_back(i);
	}
	printf("%d\n",cnt);
	for(i=1;i<=n;i++)
		if(!V[i].empty())
		{
			printf("%d",(int)V[i].size());
			for(j=0;j<(int)V[i].size();j++)
				printf(" %d",V[i][j]);
			putchar('\n');
		}
	return 0;
}