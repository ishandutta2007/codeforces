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
const int N=500010;
int T,n,a[N];
char c[N];
stack<char> kel;
bool ok(int l,int r){
	if(l==r)return 0;
	for(int i=l,j=r;i<=r;i++,j--){
		if(c[i]!=c[j]){
			return 0;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&T);
//	T=1;
	while(T--){
		while(!kel.empty())kel.pop();
		scanf("%d",&n);
		scanf("%s",c+1);
		int l=1,ss=0;
		for(int i=1;i<=n;i++){
			if(c[i]==')'){
				if(kel.empty()){
					kel.push(c[i]);
				}
				else{
					if(kel.top()=='(')
					kel.pop();
					else
					kel.push(c[i]);
				}
			}
			else{
				kel.push(c[i]);
			}
			if(kel.empty()){
				ss++;
				l=i+1;
			}
			else{
				if(ok(l,i)){
					ss++;
					l=i+1;
					while(!kel.empty())kel.pop();
				}
			}
		}
		printf("%d %d\n",ss,n-l+1);
		
	}
	return 0;
}