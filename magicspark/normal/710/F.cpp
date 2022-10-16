#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
const int SIZE=555;
const int LEN=3e5/SIZE+15;
struct KMP{
	#define SZ 300005
	int len[SZ],fail[SZ];
	void build(string &p){
	    int len=p.size(),j=fail[0]=-1;
	    for(int i=1;i<=len;i++){
	        while(j>=0&&p[j]!=p[i-1])j=fail[j];
	        fail[i]=++j;//if(p[fail[i]-1]==p[i-1])fail[i]=fail[fail[i]];
	    }
	}
	int kmp(string &_t,string &_s,int cost){
	    int n=_t.size(),m=_s.size(),cnt=0;
	    for(int i=0,k=0;i<n;i++){
	        while(k>=0&&_s[k]!=_t[i])k=fail[k];
	        len[i]=++k;
	        if(len[i]==m)cnt+=cost;
	    }
	    //cout<<m<<" "<<*max_element(len,len+n)<<endl;
	    return cnt;
	}
}cal;
struct orz{
	string lon[LEN];
	int sz=1,cnt=0;
	int v[LEN];
	int e[300005][26];
	int val[300005];
	int p[300005];
	void insert(string &_s){
		if(_s.size()<SIZE){
			int cur=1;
			for(int i=0;i<_s.size();i++){
				int to=_s[i]-'a';
				if(e[cur][to]==0)e[cur][to]=++sz;
				cur=e[cur][to];
			}
			val[cur]++;
		}else{
			lon[cnt]=_s;
			v[cnt++]++;
		}
	}
	void erase(string &_s){
		if(_s.size()<SIZE){
			int cur=1;
			for(int i=0;i<_s.size();i++){
				int to=_s[i]-'a';
				if(e[cur][to]==0)e[cur][to]=++sz;
				cur=e[cur][to];
			}
			val[cur]--;
		}else{
			lon[cnt]=_s;
			v[cnt++]--;
		}
	}
	void calc(string &_s){
		ll ans=0;
		for(int i=0;i<_s.size();i++){
			int cur=1;
			for(int j=i;j<_s.size();j++){
				int to=_s[j]-'a';
				if(e[cur][to]==0)break;
				cur=e[cur][to];
				ans+=val[cur];
			}
		}
		cal.build(_s);
		for(int i=0;i<cnt;i++)if(lon[i].size()<=_s.size())ans+=cal.kmp(_s,lon[i],v[i]);
		cout<<ans<<endl;
	}
}solve;
char input[333333];
string read(){
	scanf("%s",input);
	return input;
}
int main(){
//	freopen("data.cpp","r",stdin);
	int t;
	scanf("%d",&t);int tt=t;
	while(t--){
		int type;scanf("%d",&type);
		string s=read();
		if(type==1)solve.insert(s);
		if(type==2)solve.erase(s);
		if(type==3)solve.calc(s);
	}
	return 0;
}