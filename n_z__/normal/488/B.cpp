#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	sort(a+1,a+1+n);
	if(n==0){cout<<"YES\n1\n1\n3\n3"<<endl;return 0;}
	if(n==4){
		if((a[1]+a[2]+a[3]+a[4])==(a[2]+a[3])*2&&(a[2]+a[3])*2==(a[4]-a[1])*4)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
	if(n==1){
		a[4]=3*a[1];
		a[2]=a[1];
		a[3]=3*a[1];
		cout<<"YES"<<endl<<a[2]<<endl<<a[3]<<endl<<a[4]<<endl;
		return 0;
	}
	if(n==2){
		if(3*a[1]>=a[2])cout<<"YES"<<endl<<4*a[1]-a[2]<<endl<<3*a[1]<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
	if(n==3){
		if(a[3]==3*a[1])cout<<"YES"<<endl<<4*a[1]-a[2]<<endl;
		else if(3*a[1]>=a[3]&&a[2]+a[3]==4*a[1])cout<<"YES"<<endl<<3*a[1]<<endl;
		else if(a[3]%3==0&&a[1]+a[2]==4*a[3]/3)cout<<"YES"<<endl<<a[3]/3<<endl;
		else cout<<"NO"<<endl;
		return 0;
	}
}