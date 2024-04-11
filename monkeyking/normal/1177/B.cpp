#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;

void itoafuck(ll x,char buf[],ll d)
{
	int len=0;
	ll tx=x;
	string c="";
	while(tx)
	{
		c.push_back(tx%10+'0');
		tx/=10;
		len++;
	}
	reverse(all(c));
	for(int i=0;i<c.size();i++)
	{
		buf[i]=c[i];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	ll k;
	cin>>k;
	ll digit=1;
	ll num=9;
	for(;;digit++,num*=10)
	{
		if(k-digit*num<=0) break;
		k-=digit*num;
	}
	ll t=ceil(k,digit);
	ll x=num/9+t-1;
	char c[10000];
//	cout<<x<<endl;
	itoafuck(x,c,10);
//	cout<<c<<endl;
	cout<<c[(k-1)%digit]<<endl;
	return 0;
}