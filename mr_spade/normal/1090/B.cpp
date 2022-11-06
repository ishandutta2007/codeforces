#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
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
const int base=1091;
const int N=1e5+5;
int n,m;
hash_t key[N];
int t;
char s[N];
queue<hash_t> Q;
map<hash_t,int> M;
struct data
{
	hash_t k;
	string name;
	string art;
}d[N];
signed main()
{
	char ch;
	bool flag=1;
	hash_t xt;
	register int i;
	while(1)
	{
		while((ch=getchar())!='\\');
		t=0;
		while((ch=getchar())>='a'&&ch<='z')
			s[++t]=ch;
		if(s[1]=='b')
			break;
		while(ch!='{')
			ch=getchar();
		t=0;
		while(ch=getchar(),((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')))
			s[++t]=ch;
		xt=0;
		for(i=1;i<=t;i++)
			xt=xt*base+s[i];
		Q.push(xt);key[++n]=xt;
	}
	while(ch!='{')
		ch=getchar();
	t=0;
	while((ch=getchar())!='}')
		s[++t]=ch;
	d[0].name.clear();
	for(i=1;i<=t;i++)
		d[0].name.push_back(s[i]);
	while(ch!='{')
		ch=getchar();
	t=0;
	while((ch=getchar())!='}')
		s[++t]=ch;
	d[0].art.clear();
	for(i=1;i<=t;i++)
		d[0].art.push_back(s[i]);
	while(ch!='\\')
		ch=getchar();
	while(1)
	{
		t=0;
		while((ch=getchar())>='a'&&ch<='z')
			s[++t]=ch;
		if(s[1]=='e')
			break;
		while(ch!='{')
			ch=getchar();
		t=0;
		while(ch=getchar(),((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')))
			s[++t]=ch;
		xt=0;
		for(i=1;i<=t;i++)
			xt=xt*base+s[i];
		if(!(xt==Q.front()))
			flag=0;
		Q.pop();
		m++;
		d[m].k=xt;
		d[m].name.clear();
		for(i=1;i<=t;i++)
			d[m].name.push_back(s[i]);
		while(ch!='}')
			ch=getchar();
		d[m].art.clear();
		while((ch=getchar())!='\\')
			d[m].art.push_back(ch);
	}
	while(ch!='{')
		ch=getchar();
	t=0;
	while(ch=getchar(),((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')))
		s[++t]=ch;
	d[m+1].name.clear();
	for(i=1;i<=t;i++)
		d[m+1].name.push_back(s[i]);
	while(ch!='}')
		ch=getchar();
	if(flag)
	{
		puts("Correct");
		return 0;
	}
	puts("Incorrect");
	for(i=1;i<=m;i++)
		M[d[i].k]=i;
	printf("\\begin{");
	cout<<d[0].name;
	printf("}{");
	cout<<d[0].art;
	printf("}\n");
	for(i=1;i<=n;i++)
	{
		int x=M[key[i]];
		printf("\\bibitem{");
		cout<<d[x].name;
		printf("}");
		cout<<d[x].art;
		if(d[x].art.back()!='\n')
			putchar('\n');
	}
	printf("\\end{");
	cout<<d[m+1].name;
	printf("}\n");
	return 0;
}