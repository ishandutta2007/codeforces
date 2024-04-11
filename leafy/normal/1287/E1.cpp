#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005,mod=998244353;
inline int pls(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int dec(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
inline void chkmin(int &x,int y){
	if(y<x) x=y;
}
int n;
string s[N],ans,tr[N];
int to[305];
map<string,int> p;
inline void query(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	int t=(r-l+1)*(r-l+2)/2;
	for(int i=1;i<=t;i++) cin>>s[i];
}
inline void query(int l,int r,int op){
	cout<<"? "<<l<<' '<<r<<endl;
	int t=(r-l+1)*(r-l+2)/2;
	for(int i=1;i<=t;i++) {
		cin>>s[i];sort(s[i].begin(),s[i].end());
		p[s[i]]+=op;
	}
}
inline bool cmp(string a,string b){
	return a.size()<b.size(); 
}
int main(){
	cin>>n;
	if(n==1){
		query(1,1);
		cout<<"! "<<s[1]<<endl;
	}else if(n==2){
		string t;
		query(1,1);t=t+s[1];
		query(2,2);t=t+s[1];
		cout<<"! "<<t<<endl;
	}else {
		query(1,n,1);
		query(2,n,-1);
		int cnt=0;
		for(auto t:p) {
			if(t.second!=0) tr[++cnt]=t.first;
		}
		sort(tr+1,tr+cnt+1,cmp);
		ans=tr[1];
		for(int i=2;i<=cnt;i++){
			memset(to,0,sizeof(to));
			for(int j=0;j<tr[i].size();j++) to[tr[i][j]-'a']++;
			for(int j=0;j<ans.size();j++) to[ans[j]-'a']--;
			for(int j=0;j<26;j++) if(to[j]>0) {
				ans=ans+(char)('a'+j);break;
			}
		}
		cout<<"! "<<ans<<endl;
	}
	
	return 0;
}