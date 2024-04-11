#include<bits/stdc++.h>
using namespace std;
string a[1111];int n;
bool cmp(string x,string y){
	int X,Y;
	istringstream sinx(x);
	sinx>>X;
	istringstream siny(y);
	siny>>Y;
	return X<Y;
}
int main(){
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
for(int i=0; i<300000/n; i++)
	sort(a,a+n,cmp);
	for(int i=0; i<n; i++)
		cout<<a[i]<<(i<n-1?' ':'\n');
	return 0;
}