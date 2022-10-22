#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=128;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,k,p;
unsigned C[N][N],f[N][N][N],fac=1;
int main()
{
	read(n);read(m);read(k);read(p);
	F(i,0,n)C[i][0]=1%p;
	F(i,1,n)F(j,1,n)C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
	f[0][0][0]=f[1][0][1]=1%p;
	F(i,1,m)f[0][i][0]=f[1][i][0]=1%p;
	F(i,2,n+1)
	{
		fac=fac*(unsigned long long)i%p;
		f[i][0][1]=fac%p;
		F(maxc,1,min(m,i))
			F(left,0,i)
				F(cnt,0,min(k,i-maxc)+1)
					F(cnt_,0,cnt+1)
					if(f[left][maxc-1][cnt_]&&f[i-left-1][maxc-1][cnt-cnt_])
					{
						(f[i][maxc][cnt]+=(unsigned long long)
						C[i-1][left]*f[left][maxc-1][cnt_]%p*f[i-left-1][maxc-1][cnt-cnt_]%p
						)%=p;
					}
		F(maxc,min(m,i),min(m,n))f[i][maxc][0]=fac%p;
	}
	printf("%d\n",f[n][m-1][k]);
	return 0;
}