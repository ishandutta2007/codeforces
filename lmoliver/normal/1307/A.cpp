#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		LL n,d;
		cin>>n>>d;
		LL ans=0;
		for(int i=0;i<n;i++){
			LL a;
			cin>>a;
			while(a>0&&d-i>=0){
				a--;
				d-=i;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}