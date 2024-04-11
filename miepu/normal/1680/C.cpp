#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	string s;cin>>s;
	int n=s.size();
	
	int L=0,R=n-1;
	while(L<n&&s[L]=='0')L++;
	while(R>=0&&s[R]=='0')R--;
	int fl=1;
	for(int i=L;i<=R;i++)fl&=s[i]=='1';
	if(fl){
		cout<<0<<endl;
		return;
	}
	
	int _0=count(s.begin(),s.end(),'0');
	int _1=count(s.begin(),s.end(),'1');
	
	int l=1,r=n,res=n;
	while(l<=r){
		int mid=(l+r)>>1;
		int cnt=0,fl=0;
		for(int l=0,r=-1;l<n;l++){
			if(l&&s[l-1]=='0')cnt--;
			while(r<n-1&&(cnt<mid||s[r+1]=='1')){
				r++;cnt+=s[r]=='0';
			}
			int nw1=_1-(r-l+1)+cnt;
			fl|=nw1<=mid;
		}
		if(fl)res=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}