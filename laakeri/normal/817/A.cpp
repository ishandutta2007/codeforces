#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void nie(){
	cout<<"NO"<<endl;
	exit(0);
}

int main() {
	ll xa,ya,xb,yb;
	cin>>xa>>ya>>xb>>yb;
	ll x,y;
	cin>>x>>y;
	xb-=xa;
	yb-=ya;
	if (xb%x!=0) nie();
	if (yb%y!=0) nie();
	if (((xb/x)+(yb/y))%2!=0) nie();
	cout<<"YES"<<endl;
}