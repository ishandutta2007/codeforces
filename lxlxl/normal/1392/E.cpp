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

const int maxn = 30;

int n,Q;
ll a[maxn][maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	
	cin>>n;
	for(int i=3;i<n+n;i++)
	{
		int x=max(i-n,1),y=i-x;
		ll now=0;
		while(x<=n)
		{
			a[x][y]=now;
			now^=1ll<<(i-3);
			x++,y--;
		}
	}
	
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%lld%c",a[i][j]," \n"[j==n]);
	fflush(stdout);
	
	cin>>Q;
	while(Q--)
	{
		ll k; cin>>k;
		int x=1,y=1;
		for(int i=1;i<2*n-1;i++)
		{
			cout<<x<<" "<<y<<endl;
			ll c=k&1ll; k>>=1;
			if(y<n&& a[x][y+1] == (c<<(x+y+1-3)) ) y++;
			else x++;
		}
		cout<<n<<" "<<n<<endl;
	}
	
	return 0;
}