#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<map>
#define MAXN 100000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,m,k;
long long ans[MAXN+10];
typedef pair<int,int>pii;
set<pair<pii,int> >s[2][MAXN*2+10];
map<pii,bool>vis;
void read(){
	Read(n),Read(m),Read(k);
	int i,x,y;
	for(i=1;i<=k;i++){
		Read(x),Read(y);
		s[0][y-x+MAXN].insert(pair<pii,int>(pii(x,y),i));
		s[1][x+y].insert(pair<pii,int>(pii(x,y),i));
	}
}
void solve(){
	memset(ans,0xff,sizeof ans);
	int now=0,r;
	long long nt=0;
	pii pt(0,0),nxt;
	while(1){
		if(!now){
			r=pt.second-pt.first+MAXN;
			for(set<pair<pii,int> >::iterator i=s[0][r].begin();i!=s[0][r].end();i++){
				s[1][i->first.first+i->first.second].erase(*i);
				ans[i->second]=nt+i->first.first-pt.first;
			}
			s[0][r].clear();
			int tx=n-pt.first,ty=m-pt.second;
			if(tx==ty)
				break;
			if(tx<ty){
				nxt=pii(pt.first+tx,pt.second+tx);
				now=1;
			}
			else{
				nxt=pii(pt.first+ty,pt.second+ty);
				now=3;
			}
		}
		else if(now==1){
			r=pt.first+pt.second;
			for(set<pair<pii,int> >::iterator i=s[1][r].begin();i!=s[1][r].end();i++){
				s[0][i->first.second-i->first.first+MAXN].erase(*i);
				ans[i->second]=nt+i->first.second-pt.second;
			}
			s[1][r].clear();
			int tx=pt.first,ty=m-pt.second;
			if(tx==ty)
				break;
			if(tx<ty){
				nxt=pii(pt.first-tx,pt.second+tx);
				now=0;
			}
			else{
				nxt=pii(pt.first-ty,pt.second+ty);
				now=2;
			}
		}
		else if(now==2){
			r=pt.second-pt.first+MAXN;
			for(set<pair<pii,int> >::iterator i=s[0][r].begin();i!=s[0][r].end();i++){
				s[1][i->first.first+i->first.second].erase(*i);
				ans[i->second]=nt+pt.first-i->first.first;
			}
			s[0][r].clear();
			int tx=pt.first,ty=pt.second;
			if(tx==ty)
				break;
			if(tx<ty){
				nxt=pii(pt.first-tx,pt.second-tx);
				now=3;
			}
			else{
				nxt=pii(pt.first-ty,pt.second-ty);
				now=1;
			}
		}
		else{
			r=pt.first+pt.second;
			for(set<pair<pii,int> >::iterator i=s[1][r].begin();i!=s[1][r].end();i++){
				s[0][i->first.second-i->first.first+MAXN].erase(*i);
				ans[i->second]=nt+i->first.first-pt.first;
			}
			s[1][r].clear();
			int tx=n-pt.first,ty=pt.second;
			if(tx==ty)
				break;
			if(tx<ty){
				nxt=pii(pt.first+tx,pt.second-tx);
				now=2;
			}
			else{
				nxt=pii(pt.first+ty,pt.second-ty);
				now=0;
			}
		}
		nt+=abs(nxt.first-pt.first);
		pt=nxt;
		if(vis.count(pt))
			break;
		vis[pt]=1;
	}
}
void print(){
	int i;
	for(i=1;i<=k;i++)
		printf("%I64d\n",ans[i]);
}
int main()
{
	read();
	solve();
	print();
}