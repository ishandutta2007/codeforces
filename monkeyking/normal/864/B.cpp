#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <set>
#include <string>
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
int n;
string c;

int check(int l,int r)
{
	set <int> squ;
	for(int i=l;i<r;i++)
	{
		squ.insert((int)c[i]);
	}
	return squ.size();
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>c;
	int l=0,r=0,maxn=0;
	while(l<n && r<n)
	{
		r=l;
		while(r<n && c[r]>='a' && c[r]<='z')
		{
			r++;
		}
		if(r<=n) maxn=max(check(l,r),maxn);else break;
		l=r;
		while(l<n && c[l]>='A' && c[l]<='Z')
		{
			l++;
		}
	}
	cout<<maxn<<endl;
	return 0;
}