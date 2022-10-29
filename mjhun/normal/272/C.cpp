#include <iostream>
using namespace std;

int a[100005];

int main(){
	int n,m,i,w,h;
	long long int r=-1;
	cin>>n;
	for(i=0;i<n;++i)
		cin>>a[i];
	cin>>m;
	while(m--){
		cin>>w>>h;
		r=max(r,(long long)a[w-1]);
		cout<<r<<endl;
		r+=h;
	}
	return 0;
}