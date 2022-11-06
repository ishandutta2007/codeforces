#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[2005];
unordered_map<int,int>mp;
int main()
{
	int T;
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    int minn=1e5,flag=0;
    for(int i =1;i<=n;i++)
        {cin>>a[i];mp[a[i]]++;
          if(mp[a[i]]==2) ++flag;}
          if(flag==0) minn=0;
     for(int i=1;i<=n;i++)
     {
        for(int j=i;j<=n;j++)
         {
            mp[a[j]]--;
            if(mp[a[j]]==1) --flag;
            if(flag==0)
                minn=min(minn,j-i+1);
         }
         for(int j =i;j<=n;j++)
         {
            ++mp[a[j]];
        if(mp[a[j]]==2) ++flag;
         }

     }
    cout<<minn<<endl;
	return 0;
}