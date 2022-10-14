#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333;
int n,b,q,cur,a[N],cnt[N],ans[N];
struct query{
	int l,r,id;
	int operator<(const query&rhs)const{
		return l/b<rhs.l/b||l/b==rhs.l/b&&r<rhs.r;
	}
}p[N];
void add(int x){
	cur+=a[x]*(cnt[a[x]]++*2+1);
}
void del(int x){
	cur-=a[x]*(--cnt[a[x]]*2+1);
} 
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q,b=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=q;i++)
		cin>>p[i].l>>p[i].r,p[i].id=i;
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