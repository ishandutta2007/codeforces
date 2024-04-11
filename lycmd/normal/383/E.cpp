#include<bits/stdc++.h>
using namespace std;
int const N=17000010;
int n,ans,f[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		int t=0;
		for(int j=0;j<3;j++)
			t|=(s[j]<121)<<(s[j]-97);
		f[t]++;
	}
	for(int j=0;j<24;j++)
		for(int i=0;i<1<<24;i++)
			if(i>>j&1)
				f[i]+=f[i^1<<j];
	for(int i=0;i<1<<24;i++)
		ans^=(n-f[i])*(n-f[i]);
	cout<<ans<<"\n";
}