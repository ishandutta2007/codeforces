#include <algorithm>
#include <iostream>
using namespace std;
int a[100005];
int s[100005];
int main(){
	int n,i,r;
	cin>>n;
	for(i=0;i<n;++i) {
		cin>>r;
		a[i]=r;
		s[i]=r;
	}
	sort(s,s+n);
	i=0;
	r=0;
	while(i<n&&r<=2){
		r+=a[i]!=s[i];
		++i;
	}
	cout<<((r<=2)?"YES":"NO")<<endl;
	return 0;
}