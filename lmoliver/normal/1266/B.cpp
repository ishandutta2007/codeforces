#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(S);N<=(E);N++)

const int X=1+2+3+4+5+6-7;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		LL x;
		cin>>x;
		cout<<(x>6&&x%X>=1&&x%X<=6?"YES":"NO")<<endl;
	}
	return 0;
}