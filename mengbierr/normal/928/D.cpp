#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mod=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=300005,M=26;
char s[N];
int pts[N][M];
int prx;
int aos,rt=1,yyc=1;
int copt[N];
bool ivs[N];
bool ivsh[N];
int traos(char x){return x-'a';}
char c;
int main(){
	copt[0]=copt[1]=2;
	while(scanf("%c",&c)==1){
		if(c>='a'&&c<='z'){
			s[prx++]=c;
		}else{
			aos++;
			int st=0,ed=0;
			if(prx){
				s[prx]=0;
				int p=rt;
				For(i,0,prx){
					if(copt[p]==1&&!st)st=i;
					p=pts[p][s[i]-'a'];
					if(!ivsh[p]&&ivs[p])ed=i;
				}
				if(st&&ed)aos+=min(prx,prx-(ed-st));
				else aos+=min(prx,prx);
				if(!ivs[p]){
					p=rt;
					For(i,0,prx){
						if(!pts[p][traos(s[i])]){
							ivsh[p]=1;
							pts[p][traos(s[i])]=++yyc;
							p=pts[p][traos(s[i])];
							copt[p]++;
						}
						else{
							p=pts[p][traos(s[i])];
							copt[p]++;
						}
					}
					ivs[p]=1;
				}
			}
			prx=0;
		}
	}
	cout<<aos<<endl;
	return 0;
}