#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<string> a(n),b(m);
	
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i];
	
	int q;
	cin>>q;
	
	for(int i=0;i<q;i++){
		int y;
		cin>>y;
		
		cout<<a[(y-1)%n]<<b[(y-1)%m]<<endl;
	}
	
    return 0;
}