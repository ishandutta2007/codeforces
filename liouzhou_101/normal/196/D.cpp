#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=1000010;

int n,d;
char s[MaxN];

void init()
{
	scanf("%d%s",&d,s+1);
	n=strlen(s+1);
}

const int MOD=1000000007;
const int PRIME=31;

int POW[MaxN];

struct node
{
	node *Lc,*Rc;
	int L,R,mid;
	int val;
};

struct segment_tree
{
	int tot;
	node tree[MaxN];
	node *root;
	node *build(int L,int R)
	{
		node *it=&tree[++tot];
		it->L=L;
		it->R=R;
		if (L==R)
			it->val=s[L]-'a';
		else
		{
			it->mid=(L+R)>>1;
			it->Lc=build(L,it->mid);
			it->Rc=build(it->mid+1,R);
			it->val=((long long)it->Lc->val*POW[it->R-it->mid]+it->Rc->val)%MOD;
		}
		return it;
	}
	void set_char(node *it,int x,char c)
	{
		if (it->L==it->R)
		{
			it->val=c-'a';
			return;
		}
		if (x<=it->mid)
			set_char(it->Lc,x,c);
		else
			set_char(it->Rc,x,c);
		it->val=((long long)it->Lc->val*POW[it->R-it->mid]+it->Rc->val)%MOD;
	}
	int get(node *it,int x,int y)
	{
		if (it->L==x&&it->R==y)
			return it->val;
		if (y<=it->mid)
			return get(it->Lc,x,y);
		if (x>it->mid)
			return get(it->Rc,x,y);
		int Lv=get(it->Lc,x,it->mid);
		int Rv=get(it->Rc,it->mid+1,y);
		return ((long long)Lv*POW[y-it->mid]+Rv)%MOD;
	}
	void build()
	{
		root=build(1,n);
	}
	void set_char(int x,char c)
	{
		set_char(root,x,c);
	}
	int get(int x,int y)
	{
		return get(root,x,y);
	}
}A,B;

void set_char(int x,char c)
{
	s[x]=c;
	A.set_char(x,c);
	B.set_char(n-x+1,c);
}

bool find(int x,int d)
{
	if (x<d) return false;
	return A.get(x-d+1,x-d+d/2)==B.get(n-x+1,n-(x-d/2+1)+1);
}

bool check(int x,char c)
{
	char t=s[x];
	set_char(x,c);
	if (!find(x,d)&&!find(x,d+1)) return true;
	set_char(x,s[x]=t);
	return false;
}

void work()
{
	if (d==1)
	{
		puts("Impossible");
		return;
	}
	for (int i=POW[0]=1;i<=n;++i)
		POW[i]=(long long)POW[i-1]*PRIME%MOD;
	A.build();
	for (int i=1;i<=n/2;++i)
		swap(s[i],s[n-i+1]);
	B.build();
	for (int i=1;i<=n/2;++i)
		swap(s[i],s[n-i+1]);
	int way=n;
	for (int i=1;i<=n;++i)
		if (find(i,d)||find(i,d+1))
		{
			way=i;
			break;
		}
	for (;way>=1;--way)
		for (char c=s[way]+1;c<='z';++c)
		{
			if (!check(way,c)) continue;
			for (int i=way+1;i<=n;++i)
				for (char c='a';c<='z';++c)
					if (check(i,c)) break;
			s[n+1]=0;
			puts(s+1);
			return;
		}
	puts("Impossible");
}

int main()
{
	init();
	work();
	return 0;
}