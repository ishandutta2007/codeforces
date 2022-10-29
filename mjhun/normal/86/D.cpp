#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int x[200005];
int c[1<<20];
int n,m,bs;
ll rs[200005];
pair<pair<int,int>,int> qs[200005];

bool comp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b){
	int ba=a.fst.fst/bs,bb=b.fst.fst/bs;
	return ba<bb||(ba==bb&&a.fst.snd<b.fst.snd); 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>x[i];
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		qs[i]=mp(mp(a-1,b),i);
	}
	while(bs*bs<=n)bs++;bs--;
	sort(qs,qs+m,comp);
	int s=0,e=0;
	ll qr=0;
	for(int i=0;i<m;++i){
		int l=qs[i].fst.fst,r=qs[i].fst.snd;
		while(l!=s){
			if(l<s){
				qr-=1LL*c[x[s-1]]*c[x[s-1]]*x[s-1];
				c[x[s-1]]++;
				qr+=1LL*c[x[s-1]]*c[x[s-1]]*x[s-1];
				s--;
			}
			else {
				qr-=1LL*c[x[s]]*c[x[s]]*x[s];
				c[x[s]]--;
				qr+=1LL*c[x[s]]*c[x[s]]*x[s];
				s++;
			}
		}
		while(r!=e){
			if(r<e){
				qr-=1LL*c[x[e-1]]*c[x[e-1]]*x[e-1];
				c[x[e-1]]--;
				qr+=1LL*c[x[e-1]]*c[x[e-1]]*x[e-1];
				e--;
			}
			else {
				qr-=1LL*c[x[e]]*c[x[e]]*x[e];
				c[x[e]]++;
				qr+=1LL*c[x[e]]*c[x[e]]*x[e];
				e++;
			}		
		}
		rs[qs[i].snd]=qr;
	}
	for(int i=0;i<m;++i){
		cout<<rs[i]<<endl;
	}
	return 0;
}