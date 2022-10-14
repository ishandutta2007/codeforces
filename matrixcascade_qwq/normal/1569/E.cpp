#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define V vector<int>
using namespace std;
int n,m,k,M,a,h,f[40],g[40];
const int C=998244353;
map<int,V>S,E;
signed main(){
	cin>>k>>a>>h;n=1<<k;M=n/2;m=(1<<(1<<(k-1)));f[0]=1;up(i,1,n)f[i]=(f[i-1]*a)%C;
	up(i,0,m-1){
		int q1=0,q2=M/2,nw=i,ans=0,x,y,rk=M,R;deque<int>q;up(L,1,M)q.push_back(L);V v;v.resize(40);
		while(q.size()>1){
			x=q.front();q.pop_front();y=q.front();q.pop_front();
			if(nw&1)(ans+=x*f[rk+1])%=C,q.push_back(y),v[x]=rk+1;
			else (ans+=y*f[rk+1])%=C,q.push_back(x),v[y]=rk+1;nw>>=1;++q1;
			if(q1==q2)q2>>=1,rk>>=1,q1=0;
		}R=q.front();v[R]=1;S[(ans+R*f[1]%C)%C]=v;v[R]=2;E[(ans+R*f[2]%C)%C]=v;
	}
	int tot=0;
	up(i,0,m-1){
		int nw=i,ans=0,rk=M,q1=0,q2=M/2,R;deque<int>q;up(L,1,M)q.push_back(L+M);
		while(q.size()>1){
			int x=q.front();q.pop_front();int y=q.front();q.pop_front();
			if(nw&1)(ans+=x*f[rk+1])%=C,q.push_back(y),g[x]=rk+1;
			else (ans+=y*f[rk+1])%=C,q.push_back(x),g[y]=rk+1;nw>>=1;++q1;
			if(q1==q2)q2>>=1,rk>>=1,q1=0;
		}R=q.front();
		int t1=(h-ans-R*f[1]%C+C+C)%C,t2=(h-ans-R*f[2]%C+C+C)%C;
		if(E.find(t1)!=E.end()){
			g[R]=1;up(i,1,M)cout<<E[t1][i]<<" ";up(i,M+1,n)cout<<g[i]<<" ";goto G;
		}
		if(S.find(t2)!=S.end()){
			g[R]=2;up(i,1,M)cout<<S[t2][i]<<" ";up(i,M+1,n)cout<<g[i]<<" ";goto G;
		}
	}puts("-1");G:;
}