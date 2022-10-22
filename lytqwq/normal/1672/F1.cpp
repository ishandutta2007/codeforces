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
int tong[N],tong2[N];
vector<int> wz[N];
vector<PI> ovo;
int ans[N],top[N];
int main(){
	scanf("%d",&T);
//	T=1;
	while(T--){
		scanf("%d",&n);
		ovo.clear();
		for(int i=1;i<=n;i++){
//			ovo[i].clear();
			top[i]=0;
			wz[i].clear();
			tong2[i]=tong[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			tong[a[i]]++;
			wz[a[i]].pb(i);
		}
		for(int i=1;i<=n;i++){
			if(tong[i])
			ovo.pb(mp(tong[i],i));
		}
		sort(ovo.begin(),ovo.end());
		int len=ovo.size();
		while(ovo[len-1].fi){
			vector<int> kel;
			kel.clear();
			for(int i=len-1;i>=0;i--){
				if(ovo[i].fi){
					ovo[i].fi--;
					kel.pb(ovo[i].se);
				}
				else{
					break;
				}
			}
			int len2=kel.size();
			for(int i=1;i<len2;i++){
				ans[wz[kel[i-1]][top[kel[i-1]]]]=kel[i];
				top[kel[i-1]]++;
			}
			ans[wz[kel[len2-1]][top[kel[len2-1]]]]=kel[0];
			top[kel[len2-1]]++;
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		
	}
	return 0;
}