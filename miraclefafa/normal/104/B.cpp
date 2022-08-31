#include <iostream>
using namespace std;
long long n,x,ans;
int main() {
    cin>>n;
	for (int i=1;i<=n;i++) cin>>x,ans+=(x*i-i+1);
	cout<<ans;
}