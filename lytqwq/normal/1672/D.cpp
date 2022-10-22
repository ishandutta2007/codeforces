#include<bits/stdc++.h>
#include<cstdio>
#include<cctype>
#define ll long long
#define PI pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define ui unsigned int
#define pb push_back
#define llu long long unsigned
using namespace std;
const int MB=1<<20;
struct FastIO{
	char ib[MB+100],*p,*q;
	char ob[MB+100],*r,stk[128];
	int tp;
	FastIO(){p=q=ib,r=ob,tp=0;}
	~FastIO(){fwrite(ob,1,r-ob,stdout);}
	char read_char(){if(p==q){p=ib,q=ib+fread(ib,1,MB,stdin);if(p==q)return 0;}return *p++;}
	template<typename T>
	void read_int(T& x){char c=read_char(),l=0;for(x=0;!isdigit(c);c=read_char())l=c;for(;isdigit(c);c=read_char())x=x*10-'0'+c;if(l=='-')x=-x;}
	void write_char(char c){if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);*r++=c;}
	template<typename T>
	void write_int(T x){if(x<0)write_char('-'),x=-x;do stk[++tp]=x%10+'0';while(x/=10);while(tp)write_char(stk[tp--]);}
}IO;
//IO.read_int(a);c=IO.read_char();IO.write_int(a);//IO.write_char(c);
const int N=200010;
int T,n,a[N],b[N],tong[N];
int main(){
	scanf("%d",&T);
//	T=1;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			tong[i]=0;
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		int now=n;
		int bef=0;
		int ok=1;
		for(int i=n;i>=1;i--){
			if(bef==b[i]){
				tong[b[i]]++;
				continue;
			}
			else{
				while(now>0&&a[now]!=b[i]){
					if(tong[a[now]]!=0){
						tong[a[now]]--;
						now--;
					}
					else{
						ok=0;
						break;
					}
				}
				if(!ok)break;
				if(!now){
					ok=0;
					break;
				}
				now--;
				bef=b[i];
			}
		}
		if(!ok){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}