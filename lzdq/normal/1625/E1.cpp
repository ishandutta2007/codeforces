#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5,B=600;
int n,q;
char s[MAXN];
int pre[MAXN],stk[MAXN],top;
struct Quest{
	int l,r,id;
	int b;
}qst[MAXN];
bool operator <(Quest a,Quest b){
	if(a.b!=b.b) return a.b<b.b;
	if(a.b&1) return a.r<b.r;
	return a.r>b.r;
}
int cnt[MAXN];
ll sum,ans[MAXN];
inline ll C(int x){
	if(x<2) return 0;
	return x*(x-1ll)/2;
}
inline void Del(int x){
	x=pre[x];
	sum-=C(cnt[x]);
	cnt[x]--;
	sum+=C(cnt[x]);
}
inline void Add(int x){
	x=pre[x];
	sum-=C(cnt[x]);
	cnt[x]++;
	sum+=C(cnt[x]);
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	top=1;
	for(int i=1,j=MAXN; i<=n; i++){
		if(s[i]=='('){
			pre[i]=i;
			stk[++top]=i;
		}else{
			if(top) pre[i]=pre[stk[top--]-1];
			else pre[i]=i;
		}
	}
	for(int i=1; i<=q; i++){
		int t,l,r;
		scanf("%d%d%d",&t,&l,&r);
		qst[i]=(Quest){l-1,r,i,l/B};
	}
	sort(qst+1,qst+q+1);
	for(int i=1,l=1,r=0; i<=q; i++){
		while(l<qst[i].l) Del(l++);
		while(l>qst[i].l) Add(--l);
		while(r<qst[i].r) Add(++r);
		while(r>qst[i].r) Del(r--);
		ans[qst[i].id]=sum;
	}
	for(int i=1; i<=q; i++)
		printf("%lld\n",ans[i]);
	return 0;
}