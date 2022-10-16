/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
vector<int> z_function(const string& s) {
    int n=(int)s.size();
    vector<int> z(n);
    int l=0,r=1;
    for(int i=1;i<n;++i){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if (i+z[i]>=r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}
int n,m;
string a,b,s;
struct bit{
	ll f[500005];
	bit(){
		memset(f,0,sizeof f);
	}
	void add(ll x,ll v){
		x++;
		while(x<=5e5){
			f[x]+=v;x+=x&-x;
		}
	}
	ll sum(int x){
		ll ret=0;x++;
		while(x){
			ret+=f[x];x-=x&-x;
		}
		return ret;
	}
	ll query(int l,int r){
		return sum(r)-sum(l-1);
	}
}cnt,sum;
void insert(int val,int pos){
	if(val==0)return;
	cnt.add(pos,1);
	sum.add(pos,val);
}
ll query(ll pos,ll val){
	if(val==0)return 0;
	ll count=cnt.query(pos,min((ll)5e5,pos+m-2));
	ll value=sum.query(pos,min((ll)5e5,pos+m-2));
	cerr<<"query: "<<pos<<" "<<val<<" "<<value+val*count-count*(m-1)<<endl;
	return value+val*count-count*((ll)m-1);
}
int main(){
	cin>>n>>m>>a>>b>>s;
	string sa=s+"$"+a,sb=b+"$"+s;
	reverse(sb.begin(),sb.end());
	vector<int>va=z_function(sa),vb=z_function(sb);
	vector<pair<int,int> >ea,eb;//match,pos
	for(int i=m+1;i<sa.size();i++){
		ea.push_back(make_pair(min(m-1,va[i]),i-m-1));
	}
	for(int i=m+1;i<sb.size();i++){
		eb.push_back(make_pair(min(m-1,vb[i]),b.size()-1-(i-m-1)));
	}
	sort(ea.begin(),ea.end());
	sort(eb.rbegin(),eb.rend());
	int pos=0;ll ans=0;
	for(int i=0;i<ea.size();i++){
		while(pos<eb.size()&&ea[i].first+eb[pos].first>=m){
			insert(eb[pos].first,eb[pos].second);pos++;
		}
		ans+=query(ea[i].second,ea[i].first);
	}
	cout<<ans<<endl;
	return 0;
}