#include<cstdio>
#include<deque>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int M=320,N=M*M;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int realn,n,m,a[N],c[M][N],q,ans;
deque<int> b[M];
inline void flatten(int x){F(i,0,m)a[x*m+i]=b[x].front(),b[x].pop_front();}
inline void connect(int x){F(i,0,m)b[x].push_back(a[x*m+i]);}
int main()
{
	read(n);while(m*m<n)++m;
	F(i,0,n)read(a[i]),--a[i];
	realn=n,n=m*m;
	F(i,0,n)++c[i/m][a[i]],b[i/m].push_back(a[i]);
	read(q);
	while(q--)
	{
		int opt,l,r;read(opt);read(l);read(r);--l,--r;(l+=ans)%=realn;(r+=ans)%=realn;
		if(l>r)l^=r^=l^=r;
		if(opt==1)
		{
			if(r/m-l/m>1)
			{
				int ll=l/m,rr=r/m,tmp,last;
				flatten(rr);
				tmp=a[r];
				--c[rr][tmp],++c[ll][tmp];
				for(int i=r,x=rr*m;i>x;--i)a[i]=a[i-1];
				last=a[rr*m]=b[rr-1].back();
				++c[rr][last];--c[rr-1][last];
				for(int i=rr-1;i>ll;--i)
				{
					b[i].pop_back();
					b[i].push_front(last=b[i-1].back());
					++c[i][last];--c[i-1][last];
				}
				flatten(ll);
				for(int i=ll*m+m-1;i>l;--i)a[i]=a[i-1];
				a[l]=tmp;
				connect(ll);connect(rr);
			}
			else
			{
				int tmp=0;
				flatten(l/m);
				if(r/m!=l/m)flatten(r/m),--c[r/m][a[r]],++c[l/m][a[r]];
				tmp=a[r];
				for(int i=r;i>l;--i)a[i]=a[i-1];
				a[l]=tmp;
				connect(l/m);
				if(r/m!=l/m)connect(r/m),++c[r/m][a[r/m*m]],--c[l/m][a[r/m*m]];
			}
		}
		if(opt==2)
		{
			int k;read(k);--k;(k+=ans)%=realn;ans=0;
			if(r/m-l/m>1)
			{
				int ll=l/m,rr=r/m;
				flatten(rr);
				flatten(ll);
				F(i,l,ll*m+m)if(a[i]==k)++ans;
				F(i,ll+1,rr)ans+=c[i][k];
				F(i,rr*m,r+1)if(a[i]==k)++ans;
				connect(ll);
				connect(rr);
			}
			else
			{
				flatten(l/m);
				if(r/m!=l/m)flatten(r/m);
				F(i,l,r+1)if(a[i]==k)++ans;
				connect(l/m);
				if(r/m!=l/m)connect(r/m);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}