#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,k;
	cin>>n>>m>>k;
	cout<<m*(m-1)/2<<endl;
	if(k)for(int x=m;x>1;x--)for(int y=m;y>m-x+1;y--)cout<<y<<' '<<y-1<<endl;
	else for(int x=m-1;x;x--)for(int y=1;y<=x;y++)cout<<y<<' '<<y+1<<endl;
}