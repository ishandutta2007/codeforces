#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int i,j,n1,x,y,z;
	cin>>y>>x;
	if(x==0){
		cout<<"No";
		return 0;
	}
	if((x==1 && y>0)||(x>1 && y==0)){
		cout<<"No";
		return 0;
	}
	n1=x-1;
	if((n1%2!=0 && y%2==0)||(n1%2==0 && y%2!=0)||(y<n1)){
		cout<<"NO";
		return 0;
	}	
	if((n1%2==0 && y%2==0)||(n1%2!=0 && y%2!=0)){
		cout<<"Yes";
		return 0;
	}
}