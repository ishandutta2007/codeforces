#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,a[N],b[N];
map<int,int>tr1,tr2;
int highbit(int x){
	return x?highbit(x>>1)+1:0;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,tr1.clear(),tr2.clear();
		for(int i=1;i<=n;i++)
			for(cin>>a[i];a[i];a[i]>>=1)
				tr1[a[i]]++;
		for(int i=1;i<=n;i++)
			for(cin>>b[i];b[i];b[i]>>=1)
				tr2[b[i]]++;
		int flg=1;
		for(auto j:tr1){
			int x=tr2[j.first],y=j.second;
			if(j.first&1&&x<y)flg=0;
		}
		cout<<(flg?"YES\n":"NO\n");
	}
}//