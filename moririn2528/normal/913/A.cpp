#include<iostream>
using namespace std;
const int MAX=100000007;
int main(){
	int n,m;
	cin>>n>>m;
	int s=0;
	int i,j,k;
	for(j=0,i=1;j<n;j++){
		i*=2;
		if(i>MAX)break;
	}
	s=m%i;
	cout<<s<<endl;
	return 0;
}