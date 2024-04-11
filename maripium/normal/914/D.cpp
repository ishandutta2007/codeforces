/*input
3
2 6 3
4
1 1 2 2
1 1 3 3
2 1 9
1 1 3 2
*/
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=5e5+5;
int n,node[4*N],a[N],q;
void build(int i,int l,int r){
	if(l>r)return;
	if(l==r){node[i]=a[l];return;}
	int mid=(l+r)/2;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	node[i]=__gcd(node[2*i],node[2*i+1]);
	}
void update(int i,int l,int r,int pos,int val){
	if(pos<l || pos>r || l>r)return;
	if(l==r){
		if(l==pos)a[pos]=val,node[i]=val;return;
	}
	int mid=(l+r)/2;
	update(2*i,l,mid,pos,val);
	update(2*i+1,mid+1,r,pos,val);
	node[i]=__gcd(node[2*i],node[2*i+1]);
	}
int fl(int i,int l,int r,int L,int x){
	if(node[i]%x==0 || r<L)return -1;
	if(l==r)return l;
	int mid=(l+r)/2;
	int tmp=fl(2*i,l,mid,L,x);
	if(tmp!=-1)return tmp;
	return fl(2*i+1,mid+1,r,L,x);
	}
int fr(int i,int l,int r,int R,int x){
	if(node[i]%x==0 || l>R)return -1;
	if(l==r)return l;
	int mid=(l+r)/2;
	int tmp=fr(2*i+1,mid+1,r,R,x);
	if(tmp!=-1)return tmp;
	return fr(2*i,l,mid,R,x);
	}
signed main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
build(1,1,n);
cin>>q;
while(q--){
	int type,l,r,pos,val,x;
	cin>>type;
	if(type==1){
		cin>>l>>r>>x;
		int L=fl(1,1,n,l,x);
		if(L==-1)L=n;
		else L--;
		int R=fr(1,1,n,r,x);
		if(R==-1)R=1;
		else R++;
		if(L+2 >= R)cout<<"YES\n";
		else cout<<"NO\n";
		}
	else {
		cin>>pos>>val;
		update(1,1,n,pos,val);
		}
}
}