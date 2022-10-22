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
int l[100005][2];
int r[100005][2];
int n,k;
char c[100005];
int rightmost_from_left[100005][2];
int leftmost_from_right[100005][2];

void fi()
{
	cout<<"tokitsukaze\n";
	exit(0);
}

void se()
{
	cout<<"quailty\n";
	exit(0);
}

void dr()
{
	cout<<"once again\n";
	exit(0);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	scanf("%s",c);
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='1') flag=false;
	}
	if(flag) fi();
	flag=true;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='0') flag=false;
	}
	if(flag) fi();
	int l1=n,r1=-1,l0=n,r0=-1;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='0')
		{
			l0=min(l0,i);
			r0=max(r0,i);
		}
		else
		{
			l1=min(l1,i);
			r1=max(r1,i);
		}
	}
	if(r1-l1+1<=k) fi();
	if(r0-l0+1<=k) fi();
	for(int i=0;i<n;i++)
	{
		rightmost_from_left[i][0]=-1;
		rightmost_from_left[i][1]=-1;
		leftmost_from_right[i][0]=n;
		leftmost_from_right[i][1]=n;
	}
	rightmost_from_left[0][c[0]-'0']=0;
	for(int i=1;i<n;i++)
	{
		rightmost_from_left[i][0]=rightmost_from_left[i-1][0];
		rightmost_from_left[i][1]=rightmost_from_left[i-1][1];
		rightmost_from_left[i][c[i]-'0']=i;
	}
	leftmost_from_right[n-1][c[n-1]-'0']=n-1;
	for(int i=n-2;i>=0;i--)
	{
		leftmost_from_right[i][0]=leftmost_from_right[i+1][0];
		leftmost_from_right[i][1]=leftmost_from_right[i+1][1];
		leftmost_from_right[i][c[i]-'0']=i;
	}
	for(int i=0;i<n-k+1;i++)
	{
		int l=i,r=i+k-1;
		int nl0,nl1,nr0,nr1;
		//to zero
		bool can=true;
		nl0=min(i,l0);
		nr0=max(i,r0);
		nl1=l1;
		nr1=r1;
		if(nl1>=l) nl1=leftmost_from_right[r+1][1];
		if(nr1<=r) nr1=rightmost_from_left[l-1][0];
		if(nl0==-1 || nl0==n || nl1==-1 || nl1==n || nr0==-1 || nr0==n || nr1==-1 || nr1==n)
		{
			can=false;
//			se();
		}
		if(can && nr0-nl0+1<=k) can=false;
		if(can && nr1-nl1+1<=k) can=false;
		if(can) dr();
		//to one
		can=true;
		nl1=min(i,l1);
		nr1=max(i,r1);
		nl0=l0;
		nr0=r0;
		if(nl0>=l) nl0=leftmost_from_right[r+1][0];
		if(nr0<=r) nr0=rightmost_from_left[l-1][1];
		if(nl0==-1 || nl0==n || nl1==-1 || nl1==n || nr0==-1 || nr0==n || nr1==-1 || nr1==n)
		{
			can=false;
//			se();
		}
		if(can && nr0-nl0+1<=k) can=false;
		if(can && nr1-nl1+1<=k) can=false;
		if(can) dr();
	}
	se();
	return 0;
}