#include<bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001];
int main() {
	cin>>n;
    b[0]=1;
    bool okk=false;
	for(int x=2;x<=n;x++)
    {
		cout<<"XOR 1 "<<x<<endl;
		cin>>a[x];
		if(b[a[x]]&&!okk)cout<<"OR "<<b[a[x]]<<' '<<x<<endl,cin>>a[1],a[1]^=a[x],okk=true;
		b[a[x]]=x;
	}
	if(!okk)cout<<"AND 1 "<<b[1]<<endl,cin>>a[1],cout<<"AND 1 "<<b[2]<<endl,cin>>a[0],a[1]|=a[0]&1;;
	cout<<"! "<<a[1]<<' ';
	for(int x=2;x<=n;x++)cout<<(a[x]^a[1])<<' ';
	cout<<endl;
}
/*
0 0 2 3
*/