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

int main()
{
//	freopen("input.txt","r",stdin);
	int a,b,f,k,s=0;
	cin>>a>>b>>f>>k;
	int d1=f*2,d2=a*2-d1,now=b;
	if(a==0)
	{
		cout<<0<<endl;
		exit(0);
	}
	if(k==1)
	{
		if(b<d1/2 || b<d2/2) cout<<-1<<endl,exit(0);
		else if(b<a) s++;
		cout<<s<<endl;
		return 0;
	}
	else if(k==2)
	{
		if(b<d1/2 || b<d2) cout<<-1<<endl,exit(0);
	}
	else if(b<d1 || b<d2)
	{
		cout<<-1<<endl;
		return 0;
	}
	now-=d1/2;
//	cout<<d1<<' '<<d2<<endl;
	for(int i=0;i<k-1;i++)
	{
//		cout<<now<<endl;
		if(i%2)
		{
			if(now<d1) now=b,s++;now-=d1;
		}
		else
		{
			if(now<d2) now=b,s++;now-=d2;
		}
	}
	if(k%2)
	{
		if(now<d2/2) now=b,s++;
	}
	else
	{
		if(now<d1/2) now=b,s++;
	}
	cout<<s<<endl;
	return 0;
}