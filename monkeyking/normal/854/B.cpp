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

int main()
{
//	freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	if(n!=m && m)
	{
		cout<<1<<' ';
	}
	else
	{
		cout<<0<<' ';
	}
	int maxn=m*2;
	cout<<min(maxn,n-m)<<endl;
	return 0;
}