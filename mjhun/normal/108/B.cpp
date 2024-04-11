#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int main(){
	int n,i;
	bool r=false;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;!r&&i<n-1;++i)
		r=2*a[i]>a[i+1]&&a[i]!=a[i+1];
	cout<<(r?"YES":"NO")<<endl;
	return 0;
}