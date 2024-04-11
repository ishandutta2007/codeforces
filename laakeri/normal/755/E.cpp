#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

void nie(){
	cout<<-1<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	if (n==2||n==3||k==1){
		nie();
	}
	if (k==2&&n==4){
		nie();
	}
	if (k>3){
		nie();
	}
	if (k==2){
		cout<<n-1<<'\n';
		for (int i=1;i<n;i++){
			cout<<i<<" "<<i+1<<'\n';
		}
	}
	else{
		cout<<n-1<<'\n';
		cout<<3<<" "<<1<<'\n';
		cout<<1<<" "<<4<<'\n';
		cout<<4<<" "<<2<<'\n';
		for (int i=5;i<=n;i++){
			cout<<4<<" "<<i<<'\n';
		}
	}
}