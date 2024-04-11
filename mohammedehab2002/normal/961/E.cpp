#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
using namespace std;
using namespace __gnu_pbds;
vector<int> v[200005];
int arr[200005];
tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> t;
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%d",&arr[i]);
	int cur=0;
	for (int i=1;i<=n;i++)
	v[min(arr[i],n)].push_back(i);
	long long ans=0;
	for (int i=1;i<=n;i++)
	{
		t.insert(arr[i]);
		for (int x:v[i])
		ans+=i-t.order_of_key(x)-(x<=i);
	}
	printf("%I64d",ans/2);
}