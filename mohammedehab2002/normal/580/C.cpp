#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
bool b[100005];
vector <int> v[100005];
int ans=0,n,m;
int func(int a,int cats,bool visit[])
{
	visit[a]=true;
	if (b[a-1])
	cats++;
	else
	cats=0;
	if (cats>m)
	return 0;
	int visited=v[a].size();
	for (int i=0;i<v[a].size();i++)
	{
		if (!visit[v[a][i]])
		func(v[a][i],cats,visit);
		else
		visited--;
	}
	if (!visited)
	ans++;
	return ans;
}
int main()
{
	cin >> n >> m;
	for (int i=0;i<n;i++)
	cin >> b[i];
	for (int i=0;i<n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bool arr[100005];
	memset(arr,false,sizeof(arr));
	cout << func(1,0,arr);
}