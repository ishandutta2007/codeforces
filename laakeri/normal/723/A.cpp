#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> a(3);
	cin>>a[0]>>a[1]>>a[2];
	sort(a.begin(), a.end());
	cout<<a[1]-a[0]+a[2]-a[1]<<endl;
}