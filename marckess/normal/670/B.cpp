#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n;
	int k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0; i<n;i++)
		cin>>v[i];
	int sum = 0;
	for(int i = 1; sum + i < k ; i++)
		sum += i;
	cout<<v[ k - sum - 1];
}