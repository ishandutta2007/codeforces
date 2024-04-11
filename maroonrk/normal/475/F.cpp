#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define PB push_back
#define MP make_pair
	
typedef long long ll;
typedef pair<int,int> pii;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

const int Nmax=100000;

int ans=1;

struct Pos{
	int x,y;
};

struct cmpX{
	bool operator()(const Pos& lhs,const Pos& rhs)const{
		return lhs.x!=rhs.x?lhs.x<rhs.x:lhs.y<rhs.y;
	}
};

struct cmpY{
	bool operator()(const Pos& lhs,const Pos& rhs)const{
		return lhs.y!=rhs.y?lhs.y<rhs.y:lhs.x<rhs.x;
	}
};

int xs[Nmax*2],ys[Nmax*2],xc[Nmax*2],yc[Nmax*2];
pii qs[Nmax*4];
void Solve(const vector<Pos>& ps){
	if(ps.size()==1)
		return;
	int k=0;
	for(auto p:ps){
		xs[k]=p.x,xs[k+1]=p.x+1;
		ys[k]=p.y,ys[k+1]=p.y+1;
		k+=2;
	}
	sort(xs,xs+k);
	sort(ys,ys+k);
	int xl=0,yl=0;
	int last=INT_MIN;
	REP(i,k){
		if(last!=xs[i])
			xs[xl++]=xs[i];
		last=xs[i];
	}
	last=INT_MIN;
	REP(i,k){
		if(last!=ys[i])
			ys[yl++]=ys[i];
		last=ys[i];
	}
	fill(xc,xc+xl,0);
	fill(yc,yc+yl,0);
	for(auto p:ps){
		xc[lower_bound(xs,xs+xl,p.x)-xs]++;
		yc[lower_bound(ys,ys+yl,p.y)-ys]++;
	}
	int q=0;
	REP(i,xl)
		if(xc[i]==0)
			qs[q++]=MP(xs[i],1);
	REP(i,yl)
		if(yc[i]==0)
			qs[q++]=MP(ys[i],2);
	set<Pos,cmpX> xp(ps.begin(),ps.end());
	set<Pos,cmpY> yp(ps.begin(),ps.end());
	vector<vector<Pos>> cps;
	while(q){
		int g=qs[--q].first,t=qs[q].second;
		if(t==1){
			if(xp.begin()->x<g&&g<xp.rbegin()->x){
				ans++;
				int s=(1+xp.size())/2;
				auto bg=xp.begin(),ed=xp.end();
				bool former=false;
				while(1){
					if(g<(bg++)->x){
						former=true;
						break;
					}else if((--ed)->x<g)
						break;
				}
				cps.PB(vector<Pos>());
				if(former){
					auto i=xp.begin();
					while(i->x<g){
						Pos p=*i;
						cps.back().PB(p);
						i=xp.erase(i);
						yp.erase(p);
						int j=lower_bound(ys,ys+yl,p.y)-ys;
						if(--yc[j]==0){
							qs[q++]=MP(ys[j],2);
						}
					}
				}else{
					auto i=xp.end();
					while(g<(--i)->x){
						Pos p=*i;
						cps.back().PB(p);
						i=xp.erase(i);
						yp.erase(p);
						int j=lower_bound(ys,ys+yl,p.y)-ys;
						if(--yc[j]==0){
							qs[q++]=MP(ys[j],2);
						}
					}
				}
			}
		}else{
			if(yp.begin()->y<g&&g<yp.rbegin()->y){
				ans++;
				int s=(1+yp.size())/2;
				auto bg=yp.begin(),ed=yp.end();
				bool former=false;
				while(1){
					if(g<(bg++)->y){
						former=true;
						break;
					}else if((--ed)->y<g)
						break;
				}
				cps.PB(vector<Pos>());
				if(former){
					auto i=yp.begin();
					while(i->y<g){
						Pos p=*i;
						cps.back().PB(p);
						i=yp.erase(i);
						xp.erase(p);
						int j=lower_bound(xs,xs+xl,p.x)-xs;
						if(--xc[j]==0){
							qs[q++]=MP(xs[j],1);
						}
					}
				}else{
					auto i=yp.end();
					while(g<(--i)->y){
						Pos p=*i;
						cps.back().PB(p);
						i=yp.erase(i);
						xp.erase(p);
						int j=lower_bound(xs,xs+xl,p.x)-xs;
						if(--xc[j]==0){
							qs[q++]=MP(xs[j],1);
						}
					}
				}
			}
		}
	}
	for(auto& cp:cps)
		Solve(cp);
}

int main(){
	int n=read();
	vector<Pos> ps;
	REP(i,n){
		int x=read(),y=read();
		ps.PB(Pos{x,y});
	}
	Solve(ps);
	printf("%d\n",ans);
}