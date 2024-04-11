#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
#define MAXN 200000
typedef pair<long long,int>pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
int n,k,x,cnt;
long long a[MAXN+10];
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
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
void read(){
	Read(n),Read(k),Read(x);
	int i;
	for(i=1;i<=n;i++){
		Read(a[i]);
		q.push(pii(llabs(a[i]),i));
		cnt+=a[i]<0;
	}
}
void print(long long *a){
	int i;
	for(i=1;i<=n;i++)
		printf("%I64d ",a[i]);
}
void solve(){
	if(!(cnt&1)){
		if(1ll*k*x<=q.top().first){
			if(a[q.top().second]<0)
				a[q.top().second]+=k*x;
			else
				a[q.top().second]-=k*x;
			print(a);
			return;
		}
		else{
			int t=q.top().first/x+1;
			if(a[q.top().second]<0)
				a[q.top().second]+=t*x;
			else
				a[q.top().second]-=t*x;
			k-=t;
			t=q.top().second;
			q.pop();
			q.push(pii(llabs(a[t]),t));
		}
	}
	for(int i=1;i<=k;i++){
		int t=q.top().second;
		if(a[t]<0)
			a[t]-=x;
		else
			a[t]+=x;
		q.pop();
		q.push(pii(llabs(a[t]),t));
	}
	print(a);
}
int main()
{
	read();
	solve();
}