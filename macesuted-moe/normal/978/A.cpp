#include<iostream>

using namespace std;

int a[1005],point=1,c[1005];
bool b[1005];

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=n-1;i>-1;i--)
		if(b[a[i]]==false) c[point++]=a[i],b[a[i]]=true;
	cout<<--point<<endl;
	for(int i=point;i>=1;i--) cout<<c[i]<<' ';
	cout<<endl;
	return 0;
}