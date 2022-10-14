#include<bits/stdc++.h>
using namespace std;
int t,n,k;
inline int cntdigit(int x){
	int cnt=0,res=0;
	while(x)res>>x%10&1||cnt++,res|=1<<x%10,x/=10;
	return cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>k;
		while(cntdigit(n)>k){
			int pw=1,t=n;
			while(cntdigit(t/10)>k)pw*=10,t/=10;
			n=n/pw*pw+pw;
		}
		cout<<n<<"\n";
	}
}