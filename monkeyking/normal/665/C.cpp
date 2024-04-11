#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair 
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;

int main()
{
//	freopen("input.txt","r",stdin);
	string c;
	cin>>c;
	int len=c.size();
	for(int i=1;i<len;i++)
	{
		if(c[i]!=c[i-1]) continue;
		for(c[i]='a';c[i]<='z';c[i]++)
		{
			if(c[i]!=c[i-1] && c[i]!=c[i+1]) break;
		}
	}
	cout<<c.substr(0,len)<<endl;
	return 0;
}