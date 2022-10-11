#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector <int> t;
	int n,k,i,a,b;
	cin >> n >> k;
	for (i=0;i<n;i++)
	{
		cin >> a >> b;
		if (b<k)
		t.push_back(a);
		else
		t.push_back(a-(b-k));
	}
	cout << *max_element(t.begin(),t.end());
}