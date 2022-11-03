#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1500+5,mod=998244353;
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
int n,m;
string s[N];ll h[N];
map<ll,int> mp;
int to[1005];
int main(){
	n=read(),m=read();
	to['E']=0,to['S']=1,to['T']=2;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++) h[i]=h[i]*3+to[s[i][j]];
		mp[h[i]]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			ll t=0;
			for(int k=0;k<m;k++) 
				if(s[i][k]==s[j][k]) t=t*3+to[s[i][k]];
				else {
					char a=s[i][k],b=s[j][k],c;
					if(a>b) swap(a,b);
					if(a=='E'&&b=='S') c='T';
					else if(a=='E'&&b=='T') c='S';
					else c='E';
					t=t*3+to[c];
				}
			ans+=mp[t];
		}
	printf("%d\n",ans/3);
	return 0;
}