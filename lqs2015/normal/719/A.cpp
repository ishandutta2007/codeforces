#include<iostream>
using namespace std;
int n,a[99];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==1 && a[n]==0) cout<<"UP"<<endl;
	else if (n==1 && a[n]==15) cout<<"DOWN"<<endl;
	else if (n==1) cout<<-1<<endl;
	else if (a[n]==15 && a[n-1]==14) cout<<"DOWN"<<endl;
	else if (a[n]==0 && a[n-1]==1) cout<<"UP"<<endl;
	else if (a[n]>a[n-1]) cout<<"UP"<<endl;
	else cout<<"DOWN"<<endl;
	return 0;
}