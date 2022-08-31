#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
	
typedef long long ll;

ll ans;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=300000;

int top[Nmax],btm[Nmax],ctr[Nmax+1];

void Sub(int* p,int s,int* q,int t){
	int u=INT_MAX,v=INT_MIN;
	REP(i,t){
		u=top[i]=min(u,q[i]);
		v=btm[i]=max(v,q[i]);
	}
	u=INT_MAX,v=INT_MIN;
	for(int i=s-1;i>=0;i--){
		u=min(u,p[i]);
		v=max(v,p[i]);
		int k=(v-u+1)-(s-i);
		if(k>t)
			continue;
		else if(k==0)
			continue;
		else if(u<=top[k-1]&&btm[k-1]<=v)
			ans++;
	}
	
//	cout<<"Sub "<<ans<<endl;
	
	int b=0,e=0;
	u=INT_MAX,v=INT_MIN;
	for(int i=s-1;i>=0;i--){
		u=min(u,p[i]);
		v=max(v,p[i]);
		while(e<t){
			if(u<=top[e]){
				int k=btm[e]-e;
				if(k>0)
					ctr[k]++;
				e++;
			}else
				break;
		}
		while(b<e){
			if(btm[b]<=v){
				int k=btm[b]-b;
				if(k>0)
					ctr[k]--;
				b++;
			}else
				break;
		}
		int k=u+s-i;
		ans+=ctr[k];
	}
	while(b<e){
		int k=btm[b]-b;
		if(k>0)
			ctr[k]--;
		b++;
	}
}

void Solve(int* buf,int n){
//	cout<<"Solve "<<n<<endl;
	if(n==1){
		ans++;
		return;
	}
	int s=n/2,t=n-s;
	int *p=buf,*q=buf+s;
//	cout<<ans<<endl;
	Sub(p,s,q,t);
//	cout<<ans<<endl;
	reverse(p,p+s);
	reverse(q,q+t);
	Sub(q,t,p,s);
//	cout<<ans<<endl;
	Solve(p,s);
	Solve(q,t);
}

int buf[Nmax];

int main(){
	int n=read();
	REP(i,n){
		int r=read()-1,c=read()-1;
		buf[c]=r;
	}
	Solve(buf,n);
	printf("%I64d\n",ans);
}