#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
	bool o=0;
	int n;
	cin >> n;
	int arr[n];
	for (int i=0;i<n;i++)
	cin >> arr[i],s.insert(arr[i]);
	if (s.size()>3)
	{
		cout << "NO";
		return 0;
	}
	int a=*s.begin();
	set<int>::iterator it=s.begin();
	it++;
	int c=*it;
	it=s.end();
	it--;
	int b=*it;
	if ((a+(b-a)/2==c && (b-a)%2==0) || s.size()<=2)
	cout << "YES";
	else
	cout << "NO";
}