#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
#define int long long
int n,m,k;
int a[1005][1005];
int tmp[1005];
int sumzhi[2][1005][1005];
int sumzhu[2005][1005];
int sumfu[2005][1005];
int trans[2][1005][1005];
int tmp2d[1005][1005];
int bow[1005][1005];
int tower[2][1005][1005];
int poszhu[1005][1005];
int posfu[1005][1005];
int res[1005][1005];
const int basic=1000;
 
inline int getzhu(int x,int y)
{
	return x-y+basic;
}
 
inline int getfu(int x,int y)
{
	return x+y-n+basic;
}
 
inline bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}
 
void calcpresum(int a[],int sum[],int n)
{
	for(int i=0;i<n;i++)
	{
		sum[i]=(i?sum[i-1]:0)+a[i];
	}
}
 
int getintsum(int sum[],int l,int r)
{
	return sum[r]-(l?sum[l-1]:0);
}
 
void gettower(int a[][1005],int tower[][1005])
{
//	memset(tower,0,sizeof(tower));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			tower[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		calcpresum(a[i],sumzhi[0][i],m);
	}
	for(int j=0;j<m;j++)
	{
		for(int i=0;i<n;i++)
		{
			tmp[i]=a[i][j];
		}
		calcpresum(tmp,sumzhi[1][j],n);
	}
	for(int si=0;si<n;si++)
	{
		int len=0;
		for(int k=0;k<n+m;k++)
		{
			if(out(si+k,k)) break;
			poszhu[si+k][k]=len;
			tmp[len++]=a[si+k][k];
		}
		calcpresum(tmp,sumzhu[getzhu(si,0)],len);
	}
	for(int sj=0;sj<m;sj++)
	{
		int len=0;
		for(int k=0;k<n+m;k++)
		{
			if(out(k,sj+k)) break;
			poszhu[k][sj+k]=len;
			tmp[len++]=a[k][sj+k];
		}
		calcpresum(tmp,sumzhu[getzhu(0,sj)],len);
	}
	
	for(int sj=0;sj<m;sj++)
	{
		int len=0;
		for(int k=0;k<n+m;k++)
		{
			if(out(k,sj-k)) break;
			posfu[k][sj-k]=len;
			tmp[len++]=a[k][sj-k];
		}
		calcpresum(tmp,sumfu[getfu(0,sj)],len);
//		if(sj==2) cout<<sumfu[getfu(0,2)][0]<<endl;
	}
	for(int si=0;si<n;si++)
	{
		int len=0;
		for(int k=0;k<n+m;k++)
		{
			if(out(si+k,m-1-k)) break;
			posfu[si+k][m-1-k]=len;
			tmp[len++]=a[si+k][m-1-k];
		}
		calcpresum(tmp,sumfu[getfu(si,m-1)],len);
	}
	
	int tk=k-1;
//	cout<<sumfu[getfu(0,2)][0]<<endl;
//	cout<<getintsum(sumfu[getfu(0,2-tk)],posfu[0][2-tk],posfu[0][2-tk])<<endl;
//	exit(0);
	for(int i=tk;i<n-k+1;i++)
	{
		for(int j=tk;j<m-1;j++)
		{
//			cout<<getintsum(sumzhi[1][j+1],i-tk,i+tk)<<' '<<getintsum(sumzhu[getzhu(i,j-tk)],poszhu[i][j-tk],poszhu[i][j-tk]+tk)<<' '<<getintsum(sumfu[getfu(i,j-tk)],posfu[i][j-tk]-tk,posfu[i][j-tk])<<' '<<a[i][j-tk]<<endl;
			bow[i][j]=getintsum(sumzhi[1][j+1],i-tk,i+tk)-getintsum(sumzhu[getzhu(i,j-tk)],poszhu[i][j-tk],poszhu[i][j-tk]+tk)-getintsum(sumfu[getfu(i,j-tk)],posfu[i][j-tk]-tk,posfu[i][j-tk])+a[i][j-tk];
		}
//		cout<<endl;
	}
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<bow[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
//	exit(0);
	
	for(int xAxis=tk;xAxis+tk<n;xAxis++)
	{
		for(int j=0;j<k;j++)
		{
			tower[xAxis][tk]+=getintsum(sumzhi[1][j],xAxis-j,xAxis+j);
		}
		for(int j=k;j<m;j++)
		{
			tower[xAxis][j]=tower[xAxis][j-1]+bow[xAxis][j-1];
		}
	}
//	cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<tower[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
}
 
void gethalf(int a[][1005],int trans[][1005])
{
	gettower(a,tower[0]);
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<tower[0][i][j]<<' ';
//		}
//		cout<<endl;
//	}
//
//	exit(0);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m/2;j++)
		{
			swap(a[i][j],a[i][m-1-j]);
		}
	}
	gettower(a,tower[1]);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m/2;j++)
		{
			swap(a[i][j],a[i][m-1-j]);
			swap(tower[1][i][j],tower[1][i][m-1-j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m-1;j++)
		{
			trans[i][j]=-tower[0][i][j]+tower[1][i][j+1];
		}
	}
}
 
int calcf(int x,int y)
{
	int res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			res+=a[i][j]*max(0LL,k-abs(i-x)-abs(y-j));
		}
	}
	return res;
}
 
signed main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
//			scanf("%d",a[i]+j);
		}
	}
	gethalf(a,trans[0]);
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<trans[0][i][j]<<' ';
//		}
//		cout<<endl;
//	}
	
//	return 0;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			tmp2d[j][i]=a[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=tmp2d[i][j];
		}
	}
	swap(n,m);
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	
	gethalf(a,trans[1]);
	
	
	
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<trans[1][i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	
//	exit(0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			tmp2d[j][i]=a[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=tmp2d[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			tmp2d[j][i]=trans[1][i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			trans[1][i][j]=tmp2d[i][j];
		}
	}
	swap(n,m);
	int tk=k-1;
	res[tk][tk]=calcf(tk,tk);
	
	for(int i=tk+1;i<n-k+1;i++)
	{
		res[i][tk]=res[i-1][tk]+trans[1][i-1][tk];
	}
	for(int i=tk;i<n-k+1;i++)
	{
		for(int j=tk+1;j<m-k+1;j++)
		{
			res[i][j]=res[i][j-1]+trans[0][i][j-1];
		}
	}
	
	int kx=-1,ky=-1,kmax=-1;
	
	for(int i=tk;i<n-k+1;i++)
	{
		for(int j=tk;j<m-k+1;j++)
		{
//			cout<<res[i][j]<<' ';
			if(res[i][j]>kmax)
			{
				kmax=res[i][j];
				kx=i;
				ky=j;
			}
		}
//		cout<<endl;
	}
	cout<<kx+1<<' '<<ky+1<<endl;
	return 0;
}