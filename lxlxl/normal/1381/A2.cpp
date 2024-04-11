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
#define ll long long
using namespace std;

const int maxn = 410000;

int n;
char A[maxn],B[maxn];
int ans[maxn],ansn,L,R,rev;

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d",&n);
		scanf("%s",A+1);
		scanf("%s",B+1);
		
		ansn=0;
		L=1,R=n,rev=0;
		for(int i=n;i>=1;i--)
		{
			if(rev==0)
			{
				if(A[R]==B[i]) 
				{
					R--;
				}
				else
				{
					if(A[L]!=B[i])
					{
						ans[++ansn]=i;
						L++;
						rev^=1;
					}
					else
					{
						ans[++ansn]=1;
						ans[++ansn]=i;
						L++;
						rev^=1;
					}
				}
			}
			else
			{
				if((A[L]^1)==B[i])
				{
					L++;
				}
				else
				{
					if(A[R]==B[i])
					{
						ans[++ansn]=i;
						R--;
						rev^=1;
					}
					else
					{
						ans[++ansn]=1;
						ans[++ansn]=i;
						R--;
						rev^=1;
					}
				}
			}
		}
		printf("%d",ansn);
		for(int i=1;i<=ansn;i++) printf(" %d",ans[i]);
		puts("");
	}
	
	return 0;
}