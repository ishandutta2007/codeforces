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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
vector<string>vec[105];
char get(string a,string b){
	multiset<char>ms;
	for(char c:a)ms.insert(c);
	for(char c:b)ms.erase(ms.find(c));
	return *ms.begin();
}
bool cmp(string a,string b){
	return a.size()<b.size();
}
struct char_set{
	int cnt[26]={};
	void add(char c){
		cnt[c-'a']++;
	}
	char_set operator+(char_set a){
		char_set ret;
		for(int i=0;i<26;i++)ret.cnt[i]=cnt[i]+a.cnt[i];
		return ret;
	}
	char_set operator-(char_set a){
		char_set ret;
		for(int i=0;i<26;i++)ret.cnt[i]=cnt[i]-a.cnt[i];
		return ret;
	}
	char_set operator=(char_set b){
		memcpy(cnt,b.cnt,sizeof cnt);
		return *this;
	}
}st[55];
int main(){
	cin>>n;
	cout<<"? 1 "<<n<<endl;
	fflush(stdout);
	string s;
	for(int i=0;i<n*(n+1)/2;i++){
		cin>>s;sort(s.begin(),s.end());
		vec[(int)s.size()].push_back(s);
	}
	if(n==1){
		cout<<"! "<<vec[1][0]<<endl;
		return 0;
	}
	int mid=(n+1)/2;
	multiset<string>ms;
	cout<<"? 1 "<<mid<<endl;
	fflush(stdout);
	for(int i=0;i<mid*(mid+1)/2;i++){
		cin>>s;sort(s.begin(),s.end());
		ms.insert(s);
	}
	if(mid>1){
		cout<<"? 1 "<<mid-1<<endl;
		fflush(stdout);
		for(int i=0;i<mid*(mid-1)/2;i++){
			cin>>s;sort(s.begin(),s.end());
			ms.erase(ms.find(s));
		}
	}
	vector<string>v(ms.begin(),ms.end());
	sort(v.begin(),v.end(),cmp);
	string ans="";ans.resize(n,'#');ans[0]=v[0][0];
	for(int i=1;i<v.size();i++){
		ans[i]=get(v[i],v[i-1]);
	}
	reverse(ans.begin(),ans.begin()+(int)(v.size()));
	//from 1 to mid
	for(char c:vec[n][0])st[0].add(c);
	char_set cmp=st[0];
	char_set cur;
	for(int i=1;i*2<n;i++){
		int pos=n-i;
		for(string t:vec[i+1])for(char c:t)st[i].add(c);
		cmp=cmp+st[0];
//		for(int j=0;j<8;j++)cerr<<cmp.cnt[j]<<" ";cerr<<endl;
//		for(int j=0;j<8;j++)cerr<<st[i].cnt[j]<<" ";cerr<<endl;
		cur.add(ans[i-1]);
		if(i*2<n){
			//compare to previous
			char_set tmp=cmp-st[i];
			for(int j=0;j<26;j++){
				if(tmp.cnt[j]-cur.cnt[j]){
					ans[pos]='a'+j;
				}
			}
		}
		cur.add(ans[pos]);
		cmp=cmp-cur;
	}
	for(int i=0;i<n;i++)if(ans[i]=='#'){
		multiset<char>S;
		S.clear();
		for(char c:vec[n][0])S.insert(c);
		for(int j=0;j<n;j++)if(j!=i)S.erase(S.find(ans[j]));
		ans[i]=*S.begin();
	}
	cout<<"! "<<ans<<endl;
	return 0;
}