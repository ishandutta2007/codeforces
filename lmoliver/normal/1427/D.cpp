#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return x;
}

const int N=100;
int c[N];
int pos[N];

vector<V> ans;
void qwq(V v){
	// cerr<<"qwq";
	// for(int x:v)cerr<<" "<<x;
	// cerr<<endl;
	V vv;
	int cnt=1;
	vector<V> cc;
	for(int x:v)if(x){
		vv.push_back(x);
		cc.push_back(V(c+cnt,c+cnt+x));
		cnt+=x;
	}
	reverse(cc.begin(),cc.end());
	if(vv.size()>1){
		ans.push_back(vv);
		cnt=0;
		for(auto ccc:cc)for(int x:ccc)c[++cnt]=x;
		F(i,1,cnt)pos[c[i]]=i;
		// F(i,1,cnt)cerr<<c[i]<<" ";
		// cerr<<endl;
	}
}

int main(){
	int n=read();
	F(i,1,n)pos[c[i]=read()]=i;
	int sz=0;
	int mid=(n+1)>>1;
	int l=mid+1,r=mid;
	F(i,1,n){
		if(i%2==1){
			l--;
			// cerr<<"left "<<l<<endl;
			qwq({sz,pos[l]-sz,n-pos[l]});
		}
		else{
			r++;
			// cerr<<"right "<<r<<endl;
			qwq({pos[r]-1,n-pos[r]+1-sz,sz});
		}
		sz++;
	}
	cout<<ans.size()<<endl;
	for(V v:ans){
		cout<<v.size();
		for(int x:v)cout<<" "<<x;
		cout<<endl;
	}
	F(i,1,n)assert(c[i]==i);
	return 0;
}