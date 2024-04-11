#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a+c)%2==0){
		int x=(a+c)/2;
		if(x%b==0){
			cout<<"YES";
			return ;
		}
	} 
	if(1){
		int x=(b*2-c);
		if(x%a==0&&x>0){
			cout<<"YES";
			return ;
		}
	} 
	if(1){
		int x=(b*2-a);
		if(x%c==0&&x>0){
			cout<<"YES";
			return ;
		}
	} 
	cout<<"NO";
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve(),cout<<endl;
}