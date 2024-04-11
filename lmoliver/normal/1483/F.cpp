// sto chasedeath https://www.cnblogs.com/chasedeath/p/14819940.html
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=1.1e6;
const int C=26;

namespace AC{

struct Node{
	int ch[C],fa,tfa;
	int id;
}o[N];
int nid=0;
int rt=++nid;
int insert(const char *s){
	int now=rt;
	int l=strlen(s);
	D(i,l){
		int &qaq=o[now].ch[(int)(s[i]-'a')];
		if(!qaq)qaq=++nid;
		now=qaq;
	}
	return now;
}
int q[N];
void build(){
	int *l=q+1,*r=l;
	*r++=rt;
	while(l!=r){
		int x=*l++;
		D(i,26){
			int &c=o[x].ch[i];
			int f=x==rt?rt:o[o[x].fa].ch[i];
			if(!c){
				c=f;
			}
			else{
				o[c].tfa=x;
				o[c].fa=f;
				*r++=c;
			}
		}
	}
}

}

char tmp[N];
int tail[N];
int len[N];

int sz[N],dfb[N],dfe[N];
struct Cmp{
	bool operator()(int x,int y)const{
		return dfb[tail[x]]<dfb[tail[y]];
	}
};

int main(){
	int n=read();
	F(i,1,n){
		scanf("%s",tmp);
		len[i]=strlen(tmp);
		int last=AC::insert(tmp);
		tail[i]=last;
		AC::o[last].id=i;
	}
	AC::build();
	F(i,1,AC::nid){
		int x=AC::q[i];
		int &id=AC::o[x].id;
		if(!id&&x!=AC::rt)id=AC::o[AC::o[x].fa].id;
	}
	R(i,AC::nid,1){
		int x=AC::q[i];
		sz[x]++;
		if(x!=AC::rt)sz[AC::o[x].fa]+=sz[x];
	}
	// string db_str[100];
	F(i,1,AC::nid){
		int x=AC::q[i];
		if(x==AC::rt){
			dfb[x]=1;
		}
		else{
			int fa=AC::o[x].fa;
			dfb[x]=dfe[fa]+1;
			dfe[fa]+=sz[x];
		}
		// D(i,C){
		// 	int c=AC::o[x].ch[i];
		// 	if(AC::o[c].tfa==x)db_str[c]=db_str[x]+(char)('a'+i);
		// }
		dfe[x]=dfb[x];
	}
	// F(i,1,AC::nid){
	// 	int x=AC::q[i];
	// 	cerr<<"#"<<x<<" "<<db_str[x]<<" "<<sz[x]<<" ["<<dfb[x]<<" "<<dfe[x]<<"] id="<<AC::o[x].id<<endl;
	// }
	static int dirty[N];
	int ans=0;
	F(i,1,n){
		int left=INT_MAX;
		V a;
		int l=len[i];
		for(int x=tail[i];x!=AC::rt;x=AC::o[x].tfa){
			int id=AC::o[x!=tail[i]?x:AC::o[x].fa].id;
			// cerr<<db_str[tail[id]]<<endl;
			if(id){
				int ll=l-len[id]+1;
				if(ll<left){
					left=ll;
					// cerr<<"in"<<endl;
				}
				else{
					dirty[id]=i;
					// cerr<<"dirty"<<endl;
				}
				a.push_back(id);
			}
			l--;
		}
		sort(a.begin(),a.end(),Cmp());
		a.erase(unique(a.begin(),a.end()),a.end());
		D(j,a.size()){
			int x=a[j];
			// cerr<<i<<" -> "<<x<<endl;
			if((j+1==(int)a.size()||dfb[tail[a[j+1]]]>dfe[tail[x]])&&dirty[x]!=i){
				ans++;
			}
		}
		// cerr<<"ans="<<ans<<endl;
	}
	printf("%d\n",ans);
	return 0;
}