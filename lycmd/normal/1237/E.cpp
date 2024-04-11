#include<bits/stdc++.h>
using namespace std;
int n,cur=1;
int main(){
	for(cin>>n;cur<=n;cur=cur*2+1+cur%2)
		if(cur==n||cur==n-1)
			cout<<"1\n",exit(0);
	cout<<"0\n";
}