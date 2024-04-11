#include <iostream>
#include <queue>
#include <set>
using namespace std;
set<pair<int,int> > s;
queue<int> q[400005];
bool b[400005];
int arr[400005];
int main()
{
	int n,k,c=0;
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		q[arr[i]].push(i);
	}
	for (int i=1;i<=n;i++)
	q[i].push(n);
	for (int i=0;i<n;i++)
	{
		if (b[arr[i]])
		{
			pair<int,int> p=*(s.begin());  
			s.erase(s.begin());
			q[p.second].pop();
			s.insert(make_pair(q[p.second].front(),p.second));
		}
		else
		{
			if (s.size()==k)
			{
				set<pair<int,int> >::iterator it=s.end();
				it--;
				pair<int,int> p=*it;
				s.erase(it);
				b[p.second]=0;
			}
			q[arr[i]].pop();
			s.insert(make_pair(q[arr[i]].front(),arr[i]));
			b[arr[i]]=1;
			c++;
		}
	}
	printf("%d",c);
}