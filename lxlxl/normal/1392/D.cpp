#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#include<cassert>
#define ll long long
#define db double
#define fir first
#define sec second
#define mp make_pair
using namespace std;

inline void down(int &a,const int &b){ if(a==-1||a>b)a=b; }
const int maxn = 210000;

int n;
char str[maxn];
int a[maxn];

//          1  2 i-1 i
int f[maxn][2][2][2][2];

int main()
{
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d",&n);
		scanf("%s",str+1);
		for(int i=1;i<=n;i++) a[i]=str[i]=='R';
		
		for(int i=0;i<=n;i++)
		{
			for(int k1=0;k1<2;k1++) for(int kk2=0;kk2<2;kk2++) for(int k2=0;k2<2;k2++) for(int k3=0;k3<2;k3++)
				f[i][k1][kk2][k2][k3]=-1;
		}
		
		for(int k1=0;k1<2;k1++) for(int k2=0;k2<2;k2++)
		{
			f[2][k1][k2][k1][k2]= (a[1]!=k1) + (a[2]!=k2);
		}
		for(int i=2;i<n;i++)
		{
			for(int k1=0;k1<2;k1++) for(int kk2=0;kk2<2;kk2++) for(int k2=0;k2<2;k2++) for(int k3=0;k3<2;k3++) 
			if(f[i][k1][kk2][k2][k3]!=-1)
			{
				int temp=f[i][k1][kk2][k2][k3];
				
				if(!k2)
				{
					if(!k3) down(f[i+1][k1][kk2][k3][1],temp+ (a[i+1]!=1) );
					else 
						down(f[i+1][k1][kk2][k3][0],temp+ (a[i+1]!=0) ),
						down(f[i+1][k1][kk2][k3][1],temp+ (a[i+1]!=1) );
				}
				else
				{
					if(!k3) down(f[i+1][k1][kk2][k3][0],temp+ (a[i+1]!=0) ),
							down(f[i+1][k1][kk2][k3][1],temp+ (a[i+1]!=1) );
					else
						down(f[i+1][k1][kk2][k3][0],temp+ (a[i+1]!=0) );
				}
			}
		}
		
		int ans=-1;
		for(int k1=0;k1<2;k1++) for(int kk2=0;kk2<2;kk2++) for(int k2=0;k2<2;k2++) for(int k3=0;k3<2;k3++) 
		if(f[n][k1][kk2][k2][k3]!=-1)
		{
			int ok=1;
			
			if(kk2==0)
			{
				if(k1==0&&k3==0) ok=0;
			}
			else
			{
				if(k1==1&&k3==1) ok=0;
			}
			
			if(k1==0)
			{
				if(k3==0&&k2==0) ok=0;
			}
			else
			{
				if(k3==1&&k2==1) ok=0;
			}
			
			if(ok) down(ans,f[n][k1][kk2][k2][k3]);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}