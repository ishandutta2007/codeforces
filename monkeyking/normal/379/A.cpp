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
	long long a,b,t=0,ts=0,s=0;
	cin>>a>>b;
	long long bad=0,good=a;
	while(good)
	{
		s+=good;
		bad+=good%b;
		good/=b;
		good+=bad/b;
		bad=bad%b;
	}
	cout<<s<<endl;
	return 0;
}