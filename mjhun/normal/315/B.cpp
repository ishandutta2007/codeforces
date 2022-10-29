#include <iostream>
using namespace std;

int a[100005];

int main(){
	int s=0, n, m, op, i, x;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		cin>>a[i];
		
	while(m--){
		cin>>op;
		switch(op){
			case 1:
				cin>>i>>x;
				a[i]=x-s;
				break;
			case 2:
				cin>>x;
				s+=x;
				break;
			default:
				cin>>i;
				cout<<a[i]+s<<endl;
		}
	}
	return 0;
}