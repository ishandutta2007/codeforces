#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];
int sum;
int f[N];
int cnt[60];

void solve(){
	cin>>n;sum=0;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	int ns=0;
	int mx=0;
	for(int i=1;i<=50;i++){
		ns+=f[i];
		mx=i;
		if(ns>sum){
			cout<<"NO"<<'\n';
			return ;
		}
		if(ns==sum)break;
	}
	int flag=1;
	priority_queue<int> q;
	for(int i=1;i<=n;i++)q.push(a[i]),q.push(-1);
	int lst=0;
	for(int i=mx;i>=1;i--){
		int nw=q.top();q.pop();
		if(nw<f[i])flag=0;
		nw-=f[i];
		if(lst)q.push(lst);
		lst=nw;
	}
	cout<<(!flag?"No":"Yes")<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	f[1]=f[2]=1;
	for(int i=3;i<=50;i++){
		f[i]=f[i-1]+f[i-2];
	} 
	int _T=1;cin>>_T;
	while(_T--)solve();
}