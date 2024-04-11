#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
    stack<pair<double,int> > st;
    for (int i=n-1;i>=0;i--)
    {
    	pair<long long,int> cur(arr[i],1);
    	while (!st.empty() && cur.first*st.top().second>=st.top().first*cur.second)
    	{
    		cur.first+=st.top().first;
    		cur.second+=st.top().second;
    		st.pop();
		}
		st.push(cur);
	}
	while (!st.empty())
	{
		auto cur=st.top();
		st.pop();
		for (int i=0;i<cur.second;i++)
		printf("%.12lf\n",1.0*cur.first/cur.second);
	}
}