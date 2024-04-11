#include <iostream>
using namespace std;
int a[100005];
int main() {
	int n,k,i,j,q,r;
	bool bl=true;
	cin>>n>>k;
	for(i=1;i<=n;++i)
		cin>>a[i];
	
	q = a[k];
	for(i=k+1;bl&&i<=n;++i)
		bl = a[i]==q;
	
	if(!bl)
		r=-1;
	else {
		r = k-1;
		while(r>0&&a[r]==q)
			r--;
	}
	
	cout<<r<<endl;
	
	return 0;
}