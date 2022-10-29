#include <iostream>
using namespace std;

int sr[35];
int sc[35];

int main() {
	int n,i,j,k,r=0;
	cin>>n;
	for(i=1;i<=n;++i)
		sr[i]=sc[i]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j) {
			cin>>k;
			sr[i]+=k;
			sc[j]+=k;
		}
	
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			r+= sr[i]<sc[j];
	
	cout<<r<<endl;
	
	return 0;
}