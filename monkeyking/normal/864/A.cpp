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
int s[105];
int main()
{
//	freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int a[n];
	rep(n)
	{
		cin>>a[i];
		s[a[i]]++;
	}
	set <int> squ;
	rep(n)
	{
		squ.insert(a[i]);
	}
	squ.erase(0);
	if(squ.size()!=2)
	{
		cout<<"NO\n";
		exit(0);
	}
	int s1=0,s2=0;
	rep(105)
	{
		if(s[i]==0) continue; 
		if(s1==0)
		{
			if(s[i]!=0)
			{
				s1=s[i];
			}
		}
		else
		{
			if(s1==s[i])
			{
				cout<<"YES\n";
				for(int j=0;j<105;j++)
				{
					if(squ.count(j)) cout<<j<<' ';	
				}	
			}
			else
			{
//				cout<<s1<<" "<<s[i]<<endl;
				cout<<"NO\n";
			}
			return 0;
		}
	}
	return 0;
}