#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=0;N<(int)(E);N++)
int read(){int x;scanf("%d",&x);return x;}

const int N=100100;
V f[N];
int ans[N];
map<int,int> cnt;
int bid;
bool ok(int m){
	int lim=(m+1)/2;
	for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();it++){
		if(it->second>lim){
			bid=it->first;
			return false;
		}
	}
	return true;
}

int main(){
	int t=read();
	D(_,t){
		read();
		int m=read();
		cnt.clear();
		vector<pair<int,int> > cs;
		D(i,m){
			int c=read();
			f[i].resize(c);
			D(j,c)f[i][j]=read();
			ans[i]=f[i][0];
			cnt[ans[i]]++;
			if(c>=2)cs.push_back(make_pair(i,f[i][1]));
		}
		if(!ok(m)){
			int lim=(m+1)/2;
			int cbid=cnt[bid];
			while(cbid>lim&&!cs.empty()){
				pair<int,int> p=cs.back();
				cs.pop_back();
				if(ans[p.first]==bid){
					cbid--;
					ans[p.first]=p.second;
				}
			}
			if(cbid>lim){
				puts("NO");
				continue;
			}
		}
		puts("YES");
		D(i,m)printf("%d%c",ans[i]," \n"[i+1==m]);
		D(i,m)f[i].clear();
	}
	return 0;
}