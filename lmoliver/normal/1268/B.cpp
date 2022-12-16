#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300300;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	LL ans=0;
	int x=0;
	int y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i]/2;
		if(a[i]%2==1){
			(i%2==1?x:y)++;
		}
	}
	ans+=min(x,y);
	cout<<ans<<endl;
	return 0;
}