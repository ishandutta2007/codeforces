#include<bits/stdc++.h>
#define nxt(i) ((i)%n+1)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=509;
typedef pair<int,int> pii;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,k,c[N],ans;

int main() {
	n=read(), k=read();
	if(n%2&&!(k%2)) return puts("-1"), 0;
	int sm=n,pos=1;
	rep(i,1,n) c[i]=1;
	while(sm%k!=0||c[1]>sm/k) c[pos]+=2, sm+=2, pos=nxt(pos);
	priority_queue<pii>q;
	rep(i,1,n) q.push(pii(c[i],i));
	while(!q.empty()) {
		printf("? ");
		vector<int>vq;
		rep(i,1,k) {
			int pos=q.top().second; q.pop();
			c[pos]--;  vq.push_back(pos);
			printf("%d ",pos);
		} puts(""); fflush(stdout);
		int res; scanf("%d",&res); ans^=res;
		for(auto x:vq) if(c[x]) q.push(pii(c[x],x));
	}
	printf("! %d\n",ans); fflush(stdout);
	return 0;
}