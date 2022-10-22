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

bool prime(int a,int b)
{
	int c=a;
	while(c%b)
	{
		c+=a;
	}
	return(c==a*b);
}

int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int a=n-1,b=1,ma=n-1,mb=1;
	while(1)
	{
		if(a<=b) break;
		if(prime(a,b)) ma=a,mb=b;
		a--;b++;
	}
	cout<<mb<<' '<<ma<<endl;
	return 0;
}