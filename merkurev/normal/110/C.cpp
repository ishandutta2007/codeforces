#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int n,k=0,min,imin=-1;
	cin>>n;
	min=n;
	for (int i=0;i<=n/7;i++)
	{
		int k=n-7*i;
		if (k%4==0)
		{
			if (i+k/4<min)
			{
				min = i+k/4;
				imin=i;
			}
		}
	}
	if (imin==-1) cout<<"-1"; else
	{
		for (int i=0;i<(n-7*imin)/4;i++) cout<<4;
		for (int i=0;i<imin;i++) cout<<7;
	}
		
	return 0;
}