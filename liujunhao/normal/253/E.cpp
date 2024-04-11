#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define MAXN 50000
using namespace std;
typedef pair<int,int>pii;
typedef pair<int,pii>pip;
priority_queue<pip>q;
pip tmp[MAXN+10];
template<class T>
void Read(T &x){
	char c;
	bool f=0;
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int n,cnt,x,pset[MAXN+10];
long long T,ans[MAXN+10];
struct task{
	int t,s,p,pos;
	inline task(){
	}
	inline task(int t,int s,int p,int pos):t(t),s(s),p(p),pos(pos){
	}
	bool operator<(const task&a)const{
		return t<a.t;
	}
}a[MAXN+10];
void read(){
	Read(n);
	int i,t,s,p;
	for(i=1;i<=n;i++){
		Read(t),Read(s),Read(p);
		a[i]=task(t,s,p,i);
		pset[i]=p;
	}
	Read(T);
}
long long check(int p){
	int i;
	long long ret=0;
	for(i=1;i<=cnt;i++)
		if(tmp[i].first>=p)
			ret+=tmp[i].second.second;
	for(i=x+1;a[i].t<T&&i<=n;i++)
		if(a[i].p>=p)
			ret+=a[i].s;
	return ret;
}
int Divide_Conqure(int l,int r,int t){
	int mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)<=T-t-a[x].s)
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
void solve(){
	sort(a+1,a+n+1);
	sort(pset+1,pset+n+1);
	int i;
	long long t;
	pip u;
	i=1,t=0;
	while(!q.empty()||i<=n){
		if(q.empty()||t==a[i].t){
			t=a[i].t;
			if(a[i].p==-1)
				break;
			q.push(pip(a[i].p,pii(a[i].pos,a[i].s)));
			i++;
		}
		else{
			if(i>n||t+q.top().second.second<=a[i].t){
				u=q.top(),q.pop();
				t+=u.second.second;
				ans[u.second.first]=t;
			}
			else{
				u=q.top(),q.pop();
				u.second.second-=a[i].t-t;
				q.push(u);
				t=a[i].t;
			}
		}
	}
	x=i;
	while(!q.empty()){
		tmp[++cnt]=q.top();
		q.pop();
	}
	a[i].p=Divide_Conqure(1,1000000000,t);
	int tt=lower_bound(pset+1,pset+n+1,a[i].p)-pset;
	while(a[i].p==pset[tt]&&tt<=n)
		a[i].p++,tt++;
	for(i=1;i<=cnt;i++)
		q.push(tmp[i]);
	i=x;
	printf("%d\n",a[x].p);
	while(!q.empty()||i<=n){
		if(q.empty()||t==a[i].t){
			t=a[i].t;
			q.push(pip(a[i].p,pii(a[i].pos,a[i].s)));
			i++;
		}
		else{
			if(i>n||t+q.top().second.second<=a[i].t){
				u=q.top(),q.pop();
				t+=u.second.second;
				ans[u.second.first]=t;
			}
			else{
				u=q.top(),q.pop();
				u.second.second-=a[i].t-t;
				q.push(u);
				t=a[i].t;
			}
		}
	}
}
void print(){
	int i;
	for(i=1;i<n;i++)
		printf("%I64d ",ans[i]);
	printf("%I64d\n",ans[n]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	read();
	solve();
	print();
}