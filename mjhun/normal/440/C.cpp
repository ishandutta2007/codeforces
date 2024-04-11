#include <iostream>
using namespace std;
typedef long long ll;

ll ones[17];

int f(ll n, int k, int a){
	if(!k)return n?(1<<20):a;
	if(n<0)n=-n;
	int q=n/ones[k];
	return min(f(n-q*ones[k],k-1,a+q*k),f(n-(q+1)*ones[k],k-1,a+(q+1)*k));
}

int main(){
	int i;ll n;
	for(i=1;i<17;++i){
		ones[i]=ones[i-1]*10+1;
	}
	cin>>n;
	cout<<f(n,16,0)<<endl;
	return 0;
}