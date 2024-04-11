#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
using ll=long long;
const int matSize=201;
const ll inf=LLONG_MAX/3;
struct Matrix{
	vector<vector<ll>> buf;
	int s;
	Matrix(int n){
		s=n;
		buf.resize(s,vector<ll>(s,-inf));
	}
	Matrix operator*(const Matrix& rhs)const{
		Matrix ret(s);
		REP(i,s)REP(j,s)REP(k,s)
			ret.buf[i][j]=max(ret.buf[i][j],buf[i][k]+rhs.buf[k][j]);
		return ret;
	}
};

int vbuf[200];
string state[201];
int main(){
	int n;ll l;
	scanf("%d%lld",&n,&l);
	REP(i,n)
		scanf("%d",vbuf+i);
	map<string,int> val,idx;
	REP(i,n){
		string s;
		cin>>s;
		val[s]+=vbuf[i];
		REP(k,(int)s.size()+1)
			idx[s.substr(0,k)]=0;
	}
	int m=0;
	for(auto& kv:idx){
		state[m]=kv.first;
		kv.second=m++;
	}
	Matrix mat(m);
	REP(i,m)
		for(char c='a';c<='z';c++){
			string x=state[i]+c;
			int v=0,last=0;
			FOR(k,1,(int)x.size()+1)
				if(idx.find(x.substr(x.size()-k,k))!=idx.end()){
					v+=val[x.substr(x.size()-k,k)];
					last=k;
				}
			mat.buf[idx[x.substr(x.size()-last,last)]][i]=v;
		}
	Matrix ans(m);
	REP(i,m)
		ans.buf[i][i]=0;
	REP(i,60){
		if((l>>i)&1)
			ans=mat*ans;
		mat=mat*mat;
	}
	ll w=0;
	REP(i,m)
		w=max(w,ans.buf[i][0]);
	cout<<w<<endl;
}