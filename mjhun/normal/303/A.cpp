#include <iostream>
using namespace std;
int main(){
	int i,n,j;
	cin>>n;
	if(n%2==0){
		cout<<-1<<endl;
	}
	else{
		for(j=0;j<2;++j){
		for(i=0;i<n;++i)
			cout<<i<<' ';
		cout<<endl;
		}
		for(i=0;i<n;++i){
			cout<<(i*2)%n<<' ';
		}
		cout<<endl;
	}
	return 0;
}