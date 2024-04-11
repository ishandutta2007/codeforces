#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=505;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N][N],id[N],u[2*N],v[2*N],m,c[2*N],ind;
int solve(int l,int r)
{
	int max=0,p;
	if(r-l==1)return c[id[l]]=a[id[l]][id[l]],id[l];
	F(i,l,r)F(j,l,r)max=max>a[id[i]][id[j]]?max:a[id[i]][id[j]];
	c[p=ind++]=max;
	for(int i=l,j=l;i<r;i=j)
	{
		int q;
		F(k,i,r)if(a[id[i]][id[k]]!=max)
		{
			for(int kk=k;kk!=j;--kk)id[kk]^=id[kk-1]^=id[kk]^=id[kk-1];
			++j;
		}
		q=solve(i,j);
		u[m]=p;v[m++]=q;
	}
	return p;
}
int main()
{
	int root;
	read(n);ind=n;
	F(i,0,n)F(j,0,n)read(a[i][j]);
	F(i,0,n)id[i]=i;
	root=solve(0,n);
	printf("%d\n",ind);
	F(i,0,ind)printf("%d ",c[i]);
	printf("\n%d\n",root+1);
	F(i,0,m)printf("%d %d\n",v[i]+1,u[i]+1);
	return 0;
}