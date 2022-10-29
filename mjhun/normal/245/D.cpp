#include <iostream>
using namespace std;
int main(){
	int n,r,b,i,j;
	cin>>n;
	for(i=0;i<n;++i){
		r=0;
		for(j=0;j<n;++j){
			cin>>b;
			if(b!=-1)r|=b;
		}
		cout<<r<<' ';
	}
	return 0;
}