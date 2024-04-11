#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
const int N=100100;
LL l[N],r[N];
int main(){
	int n;
	cin>>n;
	F(i)cin>>l[i]>>r[i];
	LL ans=n;
	F(i)ans+=l[i]+r[i];
	sort(l,l+n);
	sort(r,r+n);
	F(i)ans-=min(l[i],r[i]);
	cout<<ans<<endl;
	return 0;
}