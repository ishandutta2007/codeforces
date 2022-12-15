#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n;
char s[N],t[N];
int a[N],b[N];
int cnt;
int p[N+N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s%s",s+1,t+1);
		for(int i=1;i<=n;++i) {
			a[i]=s[i]-'0';
			b[i]=t[i]-'0';
		}
		int l=1,r=n,f=0,q=0;cnt=0;
		for(int i=n;i>=1;--i){
			if(!f){
				if(a[r]^q==b[i]) {
					--r;
					continue;
				}
				if(a[l]^q==b[i]){p[++cnt]=1;a[l]^=1;}
				p[++cnt]=i;f^=1;q^=1;++l;
			}
			else{
				if(a[l]^q==b[i]) {
					++l;
					continue;
				}
				if(a[r]^q==b[i]){p[++cnt]=1;a[r]^=1;}
				p[++cnt]=i;f^=1;q^=1;--r;
			}
		}
		printf("%d",cnt);
		for(int i=1;i<=cnt;++i) printf(" %d",p[i]);puts("");
	}
	return 0;
}