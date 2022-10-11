#include <iostream>
#include <map>
using namespace std;
map <long long,int> cnt; 
int main()
{
	int n,m,ind=0,n1=0,n2=0;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		long long a;
		cin >> a;
		cnt[a]++;
	}
	cin >> m;
	long long a1[m],a2[m];
	for (int i=0;i<m;i++)
	cin >> a1[i];
	for (int i=0;i<m;i++)
	cin >> a2[i];
	for (int i=0;i<m;i++)
	{
		if (cnt[a1[i]]>n1)
		{
			n1=cnt[a1[i]];
			n2=cnt[a2[i]];
			ind=i;
		}
		else if (cnt[a1[i]]==n1)
		{
			if (cnt[a2[i]]>n2)
			{
				n2=cnt[a2[i]];
				ind=i;
			}
		}
	}
	cout << ind+1;
}