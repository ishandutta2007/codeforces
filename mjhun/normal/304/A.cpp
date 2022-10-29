#include <iostream>
#include <set>
using namespace std;

set<int> sq;

int main() {
	int n,a,b,r=0;
	cin>>n;
	
	for(a=1;a<=n;++a)
		sq.insert(a*a);
	
	for(a=1;a<=n;++a)
		for(b=a;b<=n;++b)
			if(sq.find(a*a+b*b)!=sq.end())
				++r;
	
	cout<<r<<endl;
	return 0;
}