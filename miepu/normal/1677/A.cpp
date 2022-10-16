#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];
int cnt[N];
int cnt2[N];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cnt[i]=0,cnt2[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			if(a[j]>a[i])
				cnt[i]++,cnt2[j]++; 
	int res=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
			if(a[i]>a[j])
				cnt[j]--;
		int nw=0;
		for(int j=i+1;j<=n;j++){
			nw-=cnt[j];
			if(a[j]>a[i])
				res+=nw;
			nw+=cnt2[j];
		}
	}
	cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}