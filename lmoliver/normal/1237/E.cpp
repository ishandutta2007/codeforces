#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)

int lg(int x){
	return x==0?-1:lg(x>>1)+1;
}

string ss;
int sc(int l,int r){
	int w=0;
	F(i,l,r-1)if(ss[i]=='y')w++;
	return w;
}
char tc(int x){
	return (x&1)?'y':'x';
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	int l=(1<<lg(n+1))-1;
	// cerr<<l<<endl;
	int d=n-l;
	assert(d>=0);
	if(n<=2){
		cout<<1<<endl;
		exit(0);
	}
	ss="xy";
	while((int)ss.size()+1<l){
		string tt=ss+tc(!sc(ss.size()>>1,ss.size()))+tc(sc(0,ss.size()>>1))+ss;
		ss=tt;
	}
	assert((int)ss.size()+1==l);
	// cerr<<ss<<endl;
	int cc=sc(0,ss.size());
	F(i,0,ss.size()-1){
		if(i%2==0&&ss[i]=='y'){
			cout<<0<<endl;
			exit(0);
		}
	}
	cout<<(d==cc||d==cc+1)<<endl;
	return 0;
}