#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,s;
signed main(){
	cin>>x>>s;
	if(s-x&1||x>s)
		cout<<"-1\n",exit(0);
	if(!s)
		cout<<"0\n",exit(0);
	if(x==s)
		cout<<"1\n"<<s<<"\n",exit(0);
	int d=s-x>>1;
	if((x+d^d)==x)
		cout<<"2\n"<<x+d<<" "<<d<<"\n",exit(0);
	cout<<"3\n"<<x<<" "<<d<<" "<<d<<"\n";
}