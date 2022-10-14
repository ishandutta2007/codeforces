#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333,B=37,MOD=23333333333333333;
int n,k,m,h[N],pw[N];
string s,t[N];
map<int,int>cnt,tmp,ord;
int gethsh(string s){
	int res=0;
	for(int i=0;i<s.size();i++)
		res=(res*B%MOD+s[i]-96)%MOD;
	return res;
}
int mul(int x,int y){
	return y?(mul((x+x)%MOD,y>>1)+(y&1?x:0))%MOD:0; 
}
int hshval(int l,int r){
	return (h[r]-mul(h[l-1],pw[r-l+1])+MOD)%MOD; 
} 
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>s>>m;
	for(int i=0;i<k;i++)
		s+=s[i];
	for(int i=1;i<=m;i++)
		cin>>t[i],cnt[gethsh(t[i])]++,ord[gethsh(t[i])]=i;
	pw[0]=1;
	for(int i=1;i<=n*k+k;i++)
		h[i]=(h[i-1]*B%MOD+s[i-1]-96)%MOD,pw[i]=pw[i-1]*B%MOD;
	for(int i=1;i<=k;i++){
		tmp=cnt;
		int flg=1;
		for(int j=0;j<n;j++){
			int v=hshval(i+j*k,i+j*k+k-1);
			if(!tmp[v]){
				flg=0;break;
			}
			tmp[v]--;
		}
		if(flg){
			cout<<"YES\n";
			for(int j=0;j<n;j++)
				cout<<ord[hshval(i+j*k,i+j*k+k-1)]<<" ";
			cout<<"\n";
			return 0;
		}
	}
	cout<<"NO\n";
}