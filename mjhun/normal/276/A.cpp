#include <iostream>
#define nINF 1<<31;
using namespace std;


int main(){
	int n,k,r,i,f,t,m;
	cin>>n>>k;
	r=nINF;
	for(i=0;i<n;++i){
		cin>>f>>t;
		m=(t>k)?f-(t-k):f;
		if(m>r)
			r=m;
	}
	cout<<r<<endl;
	return 0;
}