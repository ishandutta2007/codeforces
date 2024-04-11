#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,x,y;
char a[333333];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>x>>y;
	vector<int>vals;
	int cnt=0;
	for(int i=0;i<n;i++)cin>>a[i];
	a[n]='1';
	for(int i=0;i<=n;i++){
		if((i==0&&a[i]=='0')||(a[i]=='0'&&a[i-1]=='1')){
			cnt=1;
		}else if(a[i]=='0')cnt++;
		if(a[i]=='1'){
			if(cnt!=0)vals.push_back(cnt);
			cnt=0;
		}
	}
	if(vals.size()==0)printf("0\n");
	else printf("%I64d\n",(ll)y+min(x,y)*(vals.size()-1));
	return 0;
}