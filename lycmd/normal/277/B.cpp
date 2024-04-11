#include<bits/stdc++.h>
using namespace std;
int n,m,y,k,N=1000000;
int main(){
	cin>>n>>m;
	if(n>4&&m==3)
		cout<<"-1\n",exit(0);
	for(int i=0;i<m;i++)
		cout<<i<<" "<<(y+=k++)<<"\n";
	if(m<n)
		cout<<m+N<<" "<<y<<"\n";
	for(int i=m+1;i<n;i++)
		cout<<i+N<<" "<<(y+=--k)<<"\n";
}