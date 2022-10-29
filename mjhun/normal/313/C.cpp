#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool comp(int a, int b) {
	return a>b;
}
int main() {
	int m,k;
	unsigned long long int r=0;
	vector<int> a;
	a.push_back(0);
	cin >> m;
	for(int i=1; i<=m; i++) {
		cin>>k;
		a.push_back(k);
	}
	sort(a.begin()+1,a.end(),comp);
	k=1;
	while(k<=m) {
		for(int i=1;i<=k;i++)
			r+=a[i];
		k*=4;
	}
	cout<<r<<endl;
	return 0;
}