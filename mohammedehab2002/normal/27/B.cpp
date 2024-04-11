#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
class player{
	public:
		int c;
		vector <int> won;
		player(){
			c=0;
		}
		void push(int b){
			won.push_back(b);
		}
};
int did_win(vector <int> v,int n)
{
	if (find(v.begin(),v.end(),n)!=v.end())
	return true;
	return false;
}
int main()
{
	int n,m,a,b,i,maxi=0,x=0,p[]={0,0};
	cin >> n;
	player arr[n];
	m=n*(n-1)/2-1;
	for (i=0;i<m;i++)
	{
		cin >> a >> b;
		arr[a-1].c++;
		arr[b-1].c++;
		arr[a-1].push(b);
		if (arr[a-1].c>maxi)
		maxi=arr[a-1].c;
		if (arr[b-1].c>maxi)
		maxi=arr[b-1].c;
	}
	for (i=0;i<n;i++)
	{
		if (arr[i].c!=maxi)
		{
			p[x]=i;
			x++;
		}
	}
	for (i=1;i<=n;i++)
	{
		if (did_win(arr[p[0]].won,i)!=did_win(arr[p[1]].won,i))
		{
			if (did_win(arr[p[0]].won,i))
			{
				cout << p[0]+1 << " " << p[1]+1;
				return 0;
			}
			else
			{
				cout << p[1]+1 << " " << p[0]+1;
				return 0;
			}
		}
	}
	cout << p[0]+1 << " " << p[1]+1;
}