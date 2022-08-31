#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX_N=31000;

const int INF=1000000000;

bitset<MAX_N> eds[MAX_N];

int arr[MAX_N];
int n,m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;
		eds[a][b]=true;
	}
	
	for (int i=0;i<n;++i)
		arr[i]=i+1;
	
	for (int i=n-1;i>=0;--i)
	{
		int now=i;
		while (now+1<n && eds[arr[now]][arr[now+1]])
		{
			swap(arr[now],arr[now+1]);
			++now;
		}
	}
	for (int i=0;i<n;++i)
		cout<<arr[i]<<" ";
}