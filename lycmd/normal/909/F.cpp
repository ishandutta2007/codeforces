#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,a[N];
void solve(int x){
	if(x>0){
		int k=log2(x);
		reverse(a+(1<<k+1)-x-1,a+x+1);
		solve((1<<k+1)-x-2);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		a[i]=i;
	if(n&1)
		cout<<"NO\n";
	else{
		cout<<"YES\n",solve(n);
		for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
		cout<<"\n";
	}
	if(!(n&n-1)||n&1&&n<7)
		cout<<"NO\n";
	else{
		cout<<"YES\n";
		if(n&1){
			cout<<"3 6 1 5 7 2 4 ";
			for(int i=8;i<=n;i+=2)
				cout<<i+1<<" "<<i<<" ";
		}else{
			cout<<n-1<<" ";
			for(int i=2;i<=n-3;i+=2)
				cout<<i+1<<" "<<i<<" ";
			cout<<n<<" 1 "<<n-2<<"\n"; 
		}
	}
}