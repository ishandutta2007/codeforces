#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

bool comp1(pair<double,double> p1, pair<double,double> p2){
	return p1.fst>p2.fst||p1.fst==p2.fst&&p1.snd>p2.snd;
}

bool comp2(pair<double,double> p1, pair<double,double> p2){
	return p1.fst-p1.snd>p2.fst-p2.snd||p1.fst-p1.snd==p2.fst-p2.snd&&p1.fst>p2.fst;
}

pair<double,double> pp[2048];
pair<double,double> p[2048];
set<pair<double,int> > wa,wb,ca,cb;
double sa,sb;
int n,na,nb;
double kk[2048];

int main(){
	scanf("%d%d%d",&n,&na,&nb);
	fore(i,0,n)scanf("%lf",&pp[i].fst);
	fore(i,0,n)scanf("%lf",&pp[i].snd);
	sort(pp,pp+n,comp1);
	double r=0.;
	for(int i=n;i>=0;--i){
		fore(j,0,n)p[j]=pp[j];
		sort(p,p+i,comp2);
		wa.clear();wb.clear();ca.clear();cb.clear();
		fore(j,i,n)cb.insert(mp(p[j].snd,j));
		fore(j,0,i){
			kk[j]=(1-p[j].snd)*p[j].fst;
			ca.insert(mp(kk[j],j));
		}
		sa=sb=0;
		fore(j,0,i)sb+=p[j].snd;
		fore(j,0,i+1){
			while(!wa.empty()&&j+wa.size()>na){
				sa-=wa.begin()->fst;
				ca.insert(*wa.begin());
				wa.erase(wa.begin());
			}
			while(!cb.empty()&&i-j+wb.size()<nb){
				sb+=cb.rbegin()->fst;
				wb.insert(*cb.rbegin());
				cb.erase(*cb.rbegin());
			}
			while(!ca.empty()&&j+wa.size()<na){
				sa+=ca.rbegin()->fst;
				wa.insert(*ca.rbegin());
				ca.erase(*ca.rbegin());
			}
			if(i-j+wb.size()<=nb&&j+wa.size()<=na){
				r=max(r,sa+sb);
			}
			if(j!=i){
				sa+=p[j].fst;
				if(wa.count(mp(kk[j],j))){
					sa-=(1-p[j].snd)*p[j].fst;
					wa.erase(mp(kk[j],j));
				}
				else {
					ca.erase(mp(kk[j],j));
				}
				sb-=p[j].snd;
				cb.insert(mp((1-p[j].fst)*p[j].snd,j));
			}
		}
	}
	printf("%lf\n",r);
	return 0;
}