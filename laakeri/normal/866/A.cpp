#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a;
	cin>>a;
	if (a==1){
		cout<<1<<" "<<1<<endl;
		cout<<1<<endl;
	}
	else{
		cout<<(a-1)*2<<" "<<2<<endl;
		cout<<1<<" "<<2<<endl;
	}
}