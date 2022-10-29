#include <iostream>
using namespace std;
typedef long long ll;
int main(){
	ll a,b;
	cin>>a>>b;
	int r=0;
	for(int i=1;i<=63;++i){
		for(int j=0;j<i-1;++j){
			ll w=((1LL<<i)-1)^(1LL<<j);
			if(w>=a&&w<=b)r++;
		}
	}
	cout<<r<<endl;
	return 0;
}