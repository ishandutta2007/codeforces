#line 1 "a.cpp"
#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#line 2 "/home/kotatsugame/library/tool/FastIO.cpp"
#include<cctype>
#include<string>
const int buffer_size=1<<20;
//input
int rd_char()
{
	static char buf[buffer_size];
	static int l=buffer_size,r=buffer_size;
	if(l==r&&r==buffer_size)
	{
		r=fread(buf,sizeof(char),1<<20,stdin);
		l=0;
	}
	if(l==r)return EOF;
	return buf[l++];
}
unsigned int rd_uint()
{
	int c;
	unsigned int x=0;
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return x;
}
int rd_int()
{
	bool neg=false;
	int c=rd_char();
	long long x=0;
	if(c=='-')neg=true;
	else x=c-'0';
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return neg?-x:x;
}
unsigned long long rd_ull()
{
	int c;
	unsigned long long x=0;
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return x;
}
long long rd_ll()
{
	bool neg=false;
	int c=rd_char();
	long long x=0;
	if(c=='-')neg=true;
	else x=c-'0';
	while('0'<=(c=rd_char()))x=x*10+c-'0';
	return neg?-x:x;
}
string rd_str()
{
	string ret;
	int c;
	while((c=rd_char())!='\n'&&c!=' '&&c!=EOF)ret+=c;
	return ret;
}
//output
struct writer_struct{
	char buf[buffer_size];
	int l=0;
	~writer_struct(){fwrite(buf,sizeof(char),l,stdout);}
}writer;
void flush()
{
	fwrite(writer.buf,sizeof(char),writer.l,stdout);
	fflush(stdout);
	writer.l=0;
}
void wt(char c)
{
	if(writer.l==buffer_size)
	{
		fwrite(writer.buf,sizeof(char),buffer_size,stdout);
		writer.l=0;
	}
	writer.buf[writer.l++]=c;
}
void wt(unsigned int x)
{
	if(x==0)wt('0');
	else
	{
		char f[10];
		int sz=0;
		while(x)
		{
			f[sz++]=x%10+'0';
			x/=10;
		}
		while(sz)wt(f[--sz]);
	}
}
void wt(int x)
{
	if(x<0)wt('-'),x=-x;
	wt((unsigned int)x);
}
void wt(unsigned long long x)
{
	if(x==0)wt('0');
	else
	{
		char f[20];
		int sz=0;
		while(x)
		{
			f[sz++]=x%10+'0';
			x/=10;
		}
		while(sz)wt(f[--sz]);
	}
}
void wt(long long x)
{
	if(x<0)wt('-'),x=-x;
	wt((unsigned long long)x);
}
void wt(const char*s){while(*s!='\0')wt(*s++);}
void wt(const string&s){for(char c:s)wt(c);}
#line 7 "a.cpp"
const int x_low=-1e9,x_high=1e9;
const long long id=9e18;
struct Line {
int a, b;

Line(int a, int b) : a(a), b(b) {}

inline long long get(long long x) const { return a * x + b; }
};

struct Node {
Line x;
int l,r;

Node(const Line &x) : x{x}, l{-1}, r{-1} {}
};
vector<Node>vs;
struct DynamicLiChaoTree {

  int root;
  DynamicLiChaoTree():root(-1){vs.clear();}

  int add_line(int t, Line &x, const int &l, const int &r, const long long &x_l, const long long &x_r) {
    if(t==-1)
	{
		int sz=vs.size();
		vs.emplace_back(x);
		return sz;
	}

    long long t_l = vs[t].x.get(l), t_r = vs[t].x.get(r);

    if(t_l <= x_l && t_r <= x_r) {
      return t;
    } else if(t_l >= x_l && t_r >= x_r) {
      vs[t].x = x;
      return t;
    } else {
      int m = (l + r) / 2;
      if(m == r) --m;
      long long t_m = vs[t].x.get(m), x_m = x.get(m);
      if(t_m > x_m) {
        swap(vs[t].x, x);
        if(x_l >= t_l) vs[t].l = add_line(vs[t].l, x, l, m, t_l, t_m);
        else vs[t].r = add_line(vs[t].r, x, m + 1, r, t_m + x.a, t_r);
      } else {
        if(t_l >= x_l) vs[t].l = add_line(vs[t].l, x, l, m, x_l, x_m);
        else vs[t].r = add_line(vs[t].r, x, m + 1, r, x_m + x.a, x_r);
      }
      return t;
    }
  }

  void add_line(const int &a, const int &b) {
    Line x(a, b);
    root = add_line(root, x, x_low, x_high, x.get(x_low), x.get(x_high));
  }

  long long query(const int t, const int &l, const int &r, const int &x) const {
    if(t==-1) return id;
    if(l == r) return vs[t].x.get(x);
    int m = (l + r) / 2;
    if(m == r) --m;
    if(x <= m) return min(vs[t].x.get(x), query(vs[t].l, l, m, x));
    else return min(vs[t].x.get(x), query(vs[t].r, m + 1, r, x));
  }

  long long query(const int &x) const {
    return query(root, x_low, x_high, x);
  }
};
int N;
int t[3<<17],A[3<<17],B[3<<17];
const int W=2000;
bool ex[3<<17];
main()
{
	N=rd_uint();
	for(int i=0;i<N;i++)
	{
		t[i]=rd_uint();
		if(t[i]==1)
		{
			A[i]=-rd_int();
			B[i]=-rd_int();
			ex[i]=true;
		}
		else if(t[i]==2)A[i]=rd_uint()-1;
		else A[i]=rd_int();
	}
	for(int l=0;l<N;l+=W)
	{
		int r=min(l+W,N);
		set<int>S;
		for(int i=l;i<r;i++)
		{
			if(t[i]==2)
			{
				int id=A[i];
				ex[id]=false;
				if(id<l)S.insert(id);
			}
		}
		DynamicLiChaoTree P;
		for(int i=0;i<l;i++)if(ex[i])
		{
			P.add_line(A[i],B[i]);
		}
		for(int i=l;i<r;i++)
		{
			if(t[i]==1)
			{
				if(ex[i])P.add_line(A[i],B[i]);
				else S.insert(i);
			}
			if(t[i]==2)S.erase(A[i]);
			else if(t[i]==3)
			{
				long long ans=P.query(A[i]);
				for(int id:S)
				{
					ans=min(ans,(long long)A[id]*A[i]+B[id]);
				}
				if(ans==id)wt("EMPTY SET\n");
				else wt(-ans),wt('\n');
			}
		}
	}
}