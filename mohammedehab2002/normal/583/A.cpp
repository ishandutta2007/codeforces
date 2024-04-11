#include <iostream>
#include <vector>
using namespace std;
int arr[55][55];
vector <int> ans;
void solve(int a,int b,int n,int v)
{
	int i,test=0;
	for (i=0;i<n;i++)
	{
		if (arr[a][i])
		test++;
	}
	if (test==n)
	return;
	test=0;
	for (i=0;i<n;i++)
	{
		if (arr[i][b])
		test++;
	}
	if (test==n)
	return;
	for (i=0;i<n;i++)
        arr[a][i]=1;
	for (i=0;i<n;i++)
	arr[i][b]=1;
        ans.push_back(v);
}
int main()
{
    int n,i;
    cin >> n;
    for (i=0;i<n*n;i++)
    {
    	int a,b;
    	cin >> a >> b;
    	solve(a,b,n,i+1);
    }
    for (i=0;i<ans.size();i++)
    cout << ans[i] << ' ';
}