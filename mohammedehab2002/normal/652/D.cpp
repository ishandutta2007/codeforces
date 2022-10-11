#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <algorithm>
#include <vector>
using namespace std;
using namespace __gnu_pbds;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> t;
int arr[200005],ans[200005];
vector<pair<int,int> > v;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		arr[i]=l;
		v.push_back({r,i});
	}
	sort(v.begin(),v.end());
	for (auto i:v)
	{
		int cur=arr[i.second];
		ans[i.second]=t.size()-t.order_of_key(cur);
		t.insert(cur);
	}
	for (int i=0;i<n;i++)
	printf("%d\n",ans[i]);
}