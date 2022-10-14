#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333;
int n,q,k,b,cur,a[N],ans[N],cnt[N];
struct query{
	int l,r,id;
	int operator<(const query&rhs)const{
		return l/b<rhs.l/b||(l/b==rhs.l/b&&r<rhs.r);
	}
}p[N];
void add(int x){
	cur+=cnt[a[x]^k],cnt[a[x]]++;
}
void del(int x){
	cnt[a[x]]--,cur-=cnt[a[x]^k];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q>>k,b=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i],a[i]^=a[i-1];
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		p[i]={l-1,r,i};
	}
	sort(p+1,p+1+q);
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)del(l++);
		while(l>p[i].l)add(--l);
		while(r<p[i].r)add(++r);
		while(r>p[i].r)del(r--);
		ans[p[i].id]=cur;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}