#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(S);N<=(E);N++)

int main(){
	ios::sync_with_stdio(false);
	int r,c;
	cin>>r>>c;
	if(r==1&&c==1){
		cout<<0<<endl;
	}
	else if(r==1){
		F(i,1,c)cout<<i+1<<" ";
		cout<<endl;
	}
	else if(c==1){
		F(i,1,r)cout<<i+1<<endl;
	}
	else{
		F(i,1,r){
			F(j,r+1,r+c)cout<<(LL)i*j<<" ";
			cout<<endl;
		}
	}
	return 0;
}