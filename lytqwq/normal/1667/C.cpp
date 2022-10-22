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
int T,n,a[N];
int main(){
//	scanf("%d",&T);
	T=1;
	while(T--){
		scanf("%d",&n);
//		if(n==3){
//			printf("2\n1 1\n1 2\n");
//			return 0;
//		}
		if((n+1)%3==0){
			int x=(n+1)/3;
			printf("%d\n",n-x);
			int now=n-(n-x)/2;
			for(int i=n;i>x;i--){
				printf("%d %d\n",i,now);
				now++;
				if(now==n+1){
					now=x+1;
				}
			}
		}
		else if((n+1)%3==1){
			n--;
			int x=(n+1)/3;
			printf("%d\n",n-x+1);
			printf("%d %d\n",n+1,n+1);
			int now=n-(n-x)/2;
			for(int i=n;i>x;i--){
				printf("%d %d\n",i,now);
				now++;
				if(now==n+1){
					now=x+1;
				}
			}
		}
		else{
			if(n==1){
				printf("1\n1 1\n");
				return 0;
			}
			n-=2;
			int x=(n+1)/3;
			printf("%d\n",n-x+2);
			printf("%d %d\n",n+1,n+1);
			printf("%d %d\n",n+2,n+2);
			int now=n-(n-x)/2;
			for(int i=n;i>x;i--){
				printf("%d %d\n",i,now);
				now++;
				if(now==n+1){
					now=x+1;
				}
			}
			
		}
	}
	return 0;
}