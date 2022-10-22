#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=500+5,MaxA=100000+5;
vector<int> arr[MaxN];
vector<int> x[2][MaxA];
long long Sum[MaxA];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	rep(i,1,n) arr[i].resize(m+1);
	const int k=100000;
	rep(i,1,k)
		rep(I,0,1)
			x[I][i].push_back(0);
	rep(i,1,n) rep(j,1,m)
	{
		cin>>arr[i][j];
		++x[0][arr[i][j]][0],x[0][arr[i][j]].push_back(i);
		++x[1][arr[i][j]][0],x[1][arr[i][j]].push_back(j);
	}
	rep(i,1,k)
		rep(I,0,1)
			sort(x[I][i].begin()+1,x[I][i].end());
	long long Answer=0;
	rep(i,1,k)
		rep(I,0,1)
		{
			rep(j,1,x[I][i][0])
				Sum[j]=(Sum[j-1]+x[I][i][j]);
			rep(j,1,x[I][i][0])
				Answer+=((long long)x[I][i][j]*(j-1))-Sum[j-1];
		}
	cout<<Answer<<'\n';
	return 0;
}