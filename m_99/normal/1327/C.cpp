#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int n,m,k;
	cin>>n>>m>>k;
	
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		scanf("%d %d",&a,&b);
	}
	
	string ans = "";
	for(int i=0;i<n-1;i++)ans += 'U';
	for(int i=0;i<m-1;i++)ans += 'L';
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(i%2==0)ans += 'R';
			else ans += 'L';
		}
		ans += 'D';
	}
	cout<<ans.size()<<endl;
	cout<<ans<<endl;
	
    return 0;
}