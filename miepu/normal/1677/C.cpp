#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N],p[N],b[N],vis[N];

void solve(){
	vector<int> cir;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)vis[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		int l=1;
		for(int j=p[b[i]];j!=i;j=p[b[j]])
			vis[j]=1,l++;
		cnt+=(l&1); 
		cir.push_back(l);
	}
	sort(cir.begin(),cir.end(),[](int a,int b){
		int x=a/2*2,y=b/2*2;
		return x*b>a*y;
	});
	int res=0,l=1,r=n;
	int x=n-cnt;{
		int fs=l++,pr=fs,nw=pr,ty=1;
		for(int i=1;i<x;i++){
			if(ty==1)nw=r--;
			else nw=l++;
			res+=abs(nw-pr);
			pr=nw;
			ty^=1;
		}
		res+=abs(nw-fs);
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}