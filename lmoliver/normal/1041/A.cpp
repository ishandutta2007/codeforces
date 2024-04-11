#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int a,n;
	int l=0x7fffffff,r=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		l=min(l,a);
		r=max(r,a);
	}
	cout<<(n?(r-l+1-n):0);
	return 0;
}