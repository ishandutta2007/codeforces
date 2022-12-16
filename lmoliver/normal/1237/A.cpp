#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	bool f=true;
	while(n--){
		int a;
		cin>>a;
		if(a&1){
			a>>=1;
			if(f){
				a++;
			}
			cout<<a<<endl;
			f^=1;
		}
		else{
			cout<<(a>>1)<<endl;
		}
	}
	return 0;
}