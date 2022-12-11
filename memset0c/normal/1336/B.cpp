#include<bits/stdc++.h>
#include <climits>
#include <queue>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}

const int N=2e5+10;
int T,n[3],a[3][N];
long long ans;
std::multiset<int> set[3];

int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		for(int i=0;i<3;i++)read(n[i]);
		for(int i=0;i<3;i++)for(int j=1;j<=n[i];j++){
			read(a[i][j]);
			set[i].insert(a[i][j]);
		}
		ans=LLONG_MAX;
		for(int i=0;i<3;i++){
			for(int j=1;j<=n[i];j++){
				int l,r;
				const auto calc=[&](long long x,long long y,long long z){
					return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
				};
				const auto findleft=[&](int i,int v){
					auto it=set[i].upper_bound(v);
					return it==set[i].begin()?-1:*--it;
				};
				const auto findright=[&](int i,int v){
					auto it=set[i].lower_bound(v);
					return it==set[i].end()?-1:*it;
				};
				l=findleft((i+1)%3,a[i][j]);
				r=findright((i+2)%3,a[i][j]);
				if(~l&&~r){
				// printf(">> %d %d : %d %d %d : %lld\n",i,j,a[i][j],l,r,calc(l,r,a[i][j])); 
					ans=std::min(ans,calc(l,r,a[i][j]));
				}
				l=findleft((i+2)%3,a[i][j]);
				r=findright((i+1)%3,a[i][j]);
				if(~l&&~r){
				// printf(">> %d %d : %d %d %d : %lld\n",i,j,a[i][j],l,r,calc(l,r,a[i][j])); 
					ans=std::min(ans,calc(l,r,a[i][j]));
				}
			}
		}
		print(ans,'\n');
		for(int i=0;i<3;i++){
			set[i].clear();
		}
	}
}