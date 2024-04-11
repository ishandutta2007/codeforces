#include<bits/stdc++.h>
using namespace std;
int t,n,a,b;
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>a>>b;
		if(a+b>n-2||abs(a-b)>1){
			cout<<"-1\n";continue;
		}
		int l=1,r=n;
		switch(a-b){
			case 0:{
				cout<<"1 ",l++;
				while(b--){
					cout<<r<<" "<<l<<" ";
					l++,r--;
				}
				for(int i=l;i<=r;i++)
					cout<<i<<" ";
				cout<<"\n";
				break;
			}
			case 1:{
				cout<<"1 ",l++;
				while(b--){
					cout<<r<<" "<<l<<" ";
					l++,r--;
				}
				for(int i=r;i>=l;i--)
					cout<<i<<" ";
				cout<<"\n";
				break;
			}
			case -1:{
				cout<<n<<" ",r--;
				while(a--){
					cout<<l<<" "<<r<<" ";
					l++,r--; 
				}
				for(int i=l;i<=r;i++)
					cout<<i<<" ";
				cout<<"\n";
				break;
			}
		}
	}
}