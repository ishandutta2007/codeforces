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
map <int,bool> time;

int main()
{
//	freopen("input.txt","r",stdin);
	int n,start=1;
	cin>>n;
	int x,y,delta;
	vector <pair<int,int> >vec;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		delta=y;
		y=x+y-1;
		bool f=false;
		repj(vec.size())
		{
			int first=vec[j].first;
			int second=vec[j].second;
			if((x>=first && x<=second) || (y>=first && y<=second) || (x<=first && y>=second))
			{
				f=true;
//				break;
			}
		}
		if(f)
		{
			start=1;
			int end=start+delta-1;
			repj(vec.size())
			{
				int first=vec[j].first;
				int second=vec[j].second;
//				cout<<first<<' '<<second<<' '<<' '<<start<<' '<<end<<endl;
				if((start>=first && start<=second) || (end>=first && end<=second) ||(start<=first && end>=second))
				{
					start=second+1;
					end=start+delta-1;
					j=-1;
				}
			}
			vec.push_back(make_pair<int,int>(start,end));
			cout<<start<<' '<<end<<endl;
		}
		else
		{
			cout<<x<<' '<<y<<endl;
			vec.push_back(make_pair<int,int>(x,y));
		}
	}
	return 0;
}