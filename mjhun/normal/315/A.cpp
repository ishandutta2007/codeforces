#include <iostream>
using namespace std;
int a[105];
int b[105];
int main(){
	int n,i,j,r=0;
	bool bl;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	
	for(i=1;i<=n;++i){
		bl=false;
		for(j=1;j<=n&&!bl;++j){
			bl=i!=j&&(a[i]==b[j]);
		}
		r+=(int)bl;
	}
	
	cout<<n-r<<endl;
	return 0;
}