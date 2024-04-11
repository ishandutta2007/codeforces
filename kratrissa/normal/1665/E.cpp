#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,a[N],b[N],B,ch[N*32][2],s[N*32],cntn,ans[N];vector<int> tmp;
struct qry{int l,r,id;} q[N];
bool cmp(qry u,qry v){return b[u.l]<b[v.l]||b[u.l]==b[v.l]&&(b[u.l]&1?u.r<v.r:u.r>v.r);}
void add(int x,int k){
	int p=1;
	for(int i=29;i>=0;i--){
		bool d=x>>i&1;s[p]+=k;
		if(!ch[p][d])ch[p][d]=++cntn;
		p=ch[p][d];
	}
	s[p]+=k;
}
int query(){
	int res=1<<30,x=0,p=1;tmp.clear();
	for(int i=29;i>=0;i--){
		if(s[ch[p][0]]>=2)p=ch[p][0];
		else{
			if(s[ch[p][0]]==1){
				int t=x,tp=ch[p][0];
				for(int j=i-1;j>=0;j--)
					if(s[ch[tp][0]])tp=ch[tp][0];
					else t+=(1<<j),tp=ch[tp][1];
				tmp.push_back(t);
			}
			x+=1<<i,p=ch[p][1];
		}
	}
	if(s[p])tmp.push_back(x);
	if(s[p]>1)tmp.push_back(x);
	for(int i=0;i<tmp.size();i++)
		for(int j=i+1;j<tmp.size();j++)res=min(res,tmp[i]|tmp[j]);
	return res;
}
void solve(){
	for(int i=1;i<=cntn;i++)ch[i][0]=ch[i][1]=s[i]=0;
	scanf("%d",&n),cntn=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);B=n/sqrt(m);if(!B)B=1;
	for(int i=1;i<=n;i++)b[i]=(i-1)/B+1;
	for(int i=1,l,r;i<=m;i++)scanf("%d%d",&l,&r),q[i]=(qry){l,r,i};
	sort(q+1,q+m+1,cmp);
	for(int i=1,l=1,r=0;i<=m;i++){
		while(r<q[i].r)add(a[++r],1);
		while(l>q[i].l)add(a[--l],1);
		while(r>q[i].r)add(a[r--],-1);
		while(l<q[i].l)add(a[l++],-1);
		ans[q[i].id]=query();
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}