#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2333333;
int n,k,q,B,cur,op[N],a[N],s[N],c[N],pre[N],nxt[N],ans[N],cnt[N];
vector<int>t;
struct query{
	int l,r,id;
	int operator<(const query&rhs)const{
		return l/B<rhs.l/B||l/B==rhs.l/B&&r<rhs.r;
	}
}p[N];
void addl(int x){
	cur+=cnt[nxt[x]],cnt[c[x]]++;
}
void addr(int x){
	cur+=cnt[pre[x]],cnt[c[x]]++;
}
void dell(int x){
	cnt[c[x]]--,cur-=cnt[nxt[x]]; 
}
void delr(int x){
	cnt[c[x]]--,cur-=cnt[pre[x]]; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k,B=sqrt(n);
	for(int i=1;i<=n;i++)
		cin>>op[i],op[i]=3-op[i]*2;
	for(int i=0;i<=n;i++){
		if(i)cin>>a[i],s[i]=s[i-1]+a[i]*op[i];
		t.push_back(s[i]),t.push_back(s[i]-k),t.push_back(s[i]+k);
	}
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	for(int i=0;i<=n;i++)
		c[i]=lower_bound(t.begin(),t.end(),s[i])-t.begin(),
		pre[i]=lower_bound(t.begin(),t.end(),s[i]-k)-t.begin(),
		nxt[i]=lower_bound(t.begin(),t.end(),s[i]+k)-t.begin();
	cin>>q;
	for(int i=1;i<=q;i++)
		cin>>p[i].l>>p[i].r,p[i].l--,p[i].id=i;
	sort(p+1,p+1+q);
	int l=1,r=0;
	for(int i=1;i<=q;i++){
		while(l<p[i].l)dell(l++);
		while(l>p[i].l)addl(--l);
		while(r<p[i].r)addr(++r);
		while(r>p[i].r)delr(r--);
		ans[p[i].id]=cur;
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<"\n";
}