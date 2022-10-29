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
#define pb push_back
#define SZ(X) ((int)X.size())
using namespace std;

const int maxn = 110000;
const int maxc = 30;

int n;
char A[maxn],B[maxn];
int f[maxc][maxc];

int main()
{
	//freopen("tmp.in","r",stdin);
	
	int Tcase; scanf("%d",&Tcase);
	while(Tcase--)
	{
		scanf("%d",&n);
		scanf("%s",A);
		scanf("%s",B);
		
		memset(f,0,sizeof f);
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int x=A[i]-'a',y=B[i]-'a';
			f[x][y]=1;
			if(x>y) { ans=-1;break; }
		}
		if(ans==-1) { puts("-1"); continue; }
		
		for(int i=0;i<maxc;i++)
		{
			for(int j=i+1;j<maxc;j++) if(f[i][j])
			{
				ans++;
				for(int k=j+1;k<maxc;k++) f[j][k]|=f[i][k];
				break;
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}