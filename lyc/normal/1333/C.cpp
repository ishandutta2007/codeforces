#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
#define N 200020
int n,las;
ll a[N],s[N],ans;
map<ll,int> mp;
int read(){
    int out=0,fh=1;
    char cc=getchar();
    if (cc=='-') fh=-1;
    while (cc>'9'||cc<'0') cc=getchar();
    while (cc>='0'&&cc<='9') {out=out*10+cc-'0';cc=getchar();}
    return out*fh;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		s[i]=s[i-1]+a[i];
	}
	mp[0]=0;
	las=-1;
	for(int i=1;i<=n;++i){
		if(mp.count(s[i])){
			las=max(las,mp[s[i]]);
		}
		mp[s[i]]=i;
		ans+=i-las-1;
	}
	cout<<ans<<endl;
	return 0;
}