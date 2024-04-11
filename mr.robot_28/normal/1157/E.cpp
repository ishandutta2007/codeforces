#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> A(n);
    multiset <int> Y;
    for(int i = 0; i < n; i++)
    {
    	cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		Y.insert(x);
	}
	for(int i = 0; i < n; i++)
	{
		auto it = Y.lower_bound( n - A[i]);
		if(it == Y.end())
		{
			it = Y.begin();
		}
		cout << (A[i] + *it) % n << " ";
		Y.erase(it);
	}
	cout << "\n";
    return 0;
}