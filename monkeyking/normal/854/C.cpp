#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <sstream>
#include <stack>
#define rep(N) for(int i=0;i<N;i++)
#define mp make_pair 
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
int t[300005];

struct form
{
	int v;
	int t;
}a[300005];

bool compare(form a,form b)
{
	return(a.v>b.v);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n,k;
	set <int> squ;
	ull s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]);
		squ.insert(i+k);
		a[i-1].t=i;
		a[i-1].v=t[i];
	}
	sort(a,a+n,compare);
//	rep(n)
//	{
//		cout<<a[i].v<<' '<<a[i].t<<endl;
//	}
	int ans[n];
	rep(n)
	{
		int tt=a[i].t;
		tt=*squ.lower_bound(a[i].t);
		squ.erase(tt);
		s+=(ull)(tt-a[i].t)*a[i].v;
		ans[a[i].t-1]=tt;
	}
	cout<<s<<endl;
	rep(n)
	{
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}