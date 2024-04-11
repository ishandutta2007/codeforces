#include<bits/stdc++.h>
using namespace std;
bitset<201>a,b,c;
int main(){
	int n;
	cin>>n;
	a[1]=b[0]=1;
	for(int x=2;x<=n;x++)c=b^(a<<1),b=a,a=c;
	cout<<n<<endl;
	for(int x=0;x<=n;x++)
	cout<<a[x]<<' ';
	cout<<endl<<n-1<<endl;
	for(int x=0;x<n;x++)
	cout<<b[x]<<' ';
}