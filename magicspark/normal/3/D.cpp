#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
string s;
int a[50005],b[50005];
vector<pair<int,int> >all;
const int SIZE=65536; 
struct SegTree{
	ll f[SIZE<<2]={},lazy[SIZE<<2]={};
	void addpoint(int pos,int v){
		pos+=SIZE-1;
		f[pos]=v;
		while(pos){
			pos=pos-1>>1;
			f[pos]=min(f[pos+pos+1],f[pos+pos+2]);
		}
	}
	ll query(int l,int r,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r)return f[k]+lazy[k];
		if(r<l1||r1<l)return (ll)1e18;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		ll vl=query(l,r,l1,mid,k+k+1);
		ll vr=query(l,r,mid+1,r1,k+k+2);
		f[k]=min(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return min(vl,vr);
	}
	void addrange(int l,int r,int v,int l1=0,int r1=SIZE-1,int k=0){
		if(l<=l1&&r1<=r){
			lazy[k]+=v;
			return;
		}
		if(l1>r||r1<l)return;
		lazy[k+k+1]+=lazy[k];lazy[k+k+2]+=lazy[k];lazy[k]=0;
		int mid=l1+r1>>1;
		addrange(l,r,v,l1,mid,k+k+1);
		addrange(l,r,v,mid+1,r1,k+k+2);
		f[k]=min(f[k+k+1]+lazy[k+k+1],f[k+k+2]+lazy[k+k+2]);
		return;
	}
}data;
signed main(){
	cin>>s;int ans=0;
	for(int i=0;i<s.size();i++)if(s[i]=='?'){
		cin>>a[i]>>b[i];
		s[i]='(';ans+=a[i];
		all.push_back(make_pair(b[i]-a[i],i));
	}
	int sum=0;
	for(int i=0;i<s.size();i++){
		sum+=(s[i]=='('?1:-1);
		data.addpoint(i+1,sum);
	}
	sort(all.begin(),all.end());
	for(int i=0;i<all.size();i++){
		int v=all[i].first,pos=all[i].second;
		data.addrange(pos+1,s.size(),-2);
		if(data.query(1,s.size())>=0)ans+=v,s[pos]=')';
		else data.addrange(pos+1,s.size(),2);
	}
	int tmp=0;
	for(int i=0;i<s.size();i++){
	tmp+=(s[i]=='('?1:-1);if(tmp<0)return puts("-1")&0;}
	if(tmp)return puts("-1")&0;
	cout<<ans<<endl<<s<<endl;
	return 0;
}