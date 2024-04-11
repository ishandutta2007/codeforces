#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=1510;// oh no
const int Q=11;

int n;
int c[N][N];
int q;

typedef pair<int,int> P;
struct Seg{
	P pos[Q];
	int cnt;
	int bottom()const{
		return cnt<=q?n+1:min(n+1,pos[q].first);
	}
};
ostream &operator<<(ostream &o,P p){
	return o<<"("<<p.first<<","<<p.second<<")";
}
ostream &operator<<(ostream &o,Seg s){
	o<<"{";
	if(!s.cnt)return o<<"}";
	D(i,s.cnt)o<<s.pos[i]<<" }"[i+1==s.cnt];
	return o;
}

bool tmp[N*N];
Seg merge(Seg a,Seg b){
	static P qaq[2*Q];
	merge(a.pos,a.pos+a.cnt,b.pos,b.pos+b.cnt,qaq);
	Seg res;
	res.cnt=0;
	D(i,a.cnt+b.cnt){
		if(!tmp[qaq[i].second]){
			tmp[qaq[i].second]=true;
			res.pos[res.cnt++]=qaq[i];
			if(res.cnt==q+1)break;
		}
	}
	D(i,res.cnt)tmp[res.pos[i].second]=false;
	return res;
}
void append(Seg &a,P p){
	D(i,a.cnt){
		if(a.pos[i].second==p.second){
			R(j,i,1)a.pos[j]=a.pos[j-1];
			a.pos[0]=p;
			return;
		}
	}
	int pos=a.cnt<q+1
		?a.cnt++
		:q;
	R(j,pos,1)a.pos[j]=a.pos[j-1];
	a.pos[0]=p;
}

struct Que{
	Seg s[N];
	Seg st[N];
	int l,m,r;
	void init(){
		l=m=r=0;
	}
	void push(Seg x){
		s[r]=x;
		st[r]=m==r?x:merge(st[r-1],x);
		r++;
	}
	void pop(){
		if(l==m){
			st[r-1]=s[r-1];
			R(i,r-2,m)st[i]=merge(s[i],st[i+1]);
			m=r;
		}
		l++;
	}
	Seg query(){
		assert(l!=r);
		return l==m?st[r-1]:m==r?st[l]:merge(st[l],st[r-1]);
	}
}que;

Seg ss[N];
int ans[N];
int main(){
	n=read();
	q=read();
	F(i,1,n)F(j,1,n)c[i][j]=read();
	R(i,n,1){
		F(j,1,n)append(ss[j],P(i,c[i][j]));
		int r=0;
		que.init();
		// cerr<<"init"<<endl;
		F(l,1,n){
			while(r<=n&&(r<l||que.query().bottom()-i>=r-l+1)){
				// cerr<<"i="<<i<<" ["<<l<<","<<r<<"] valid"<<endl;
				r++;
				// cerr<<"push "<<ss[r]<<endl;
				que.push(ss[r]);
				// cerr<<"que="<<que.query()<<endl;
				// cerr<<"bot="<<que.query().bottom()<<endl;
			}
			ans[r-l]++;
			// cerr<<"pop"<<endl;
			que.pop();
		}
	}
	R(i,n,1)ans[i]+=ans[i+1];
	F(i,1,n)printf("%d\n",ans[i]);
	return 0;
}