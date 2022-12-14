#include<iostream>
using namespace std;
int n,m,k;
int main()
{
	cin>>n>>m>>k;
	cout<<(k-1)/(m*2)+1<<" ";
	k=(k-1)%(m*2)+1;
	cout<<(k-1)/2+1<<" ";
	k=(k-1)%2+1;
	if (k==1) cout<<"L"<<endl;
	else cout<<"R"<<endl;
	return 0;
}