#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,c,d;
vector<pair<pair<int,int>,int> > wc,wd,wc2,wd2;
/*
int doit(vector<pair<pair<int,int>,int> >& w, int t){
	int r=0;
	for(auto p:w){
		if(p.fst.fst>t)continue;
		int asd=p.fst.snd;
		int k=upper_bound(w.begin(),w.end(),mp(mp(t-p.fst.fst,1<<30),1<<30))-w.begin()-1;
		if(k>=0&&w[k].snd==p.snd)k--;
		if(k>=0){
			asd+=w[k].fst.snd;
			r=max(r,asd);
		}
	}
	return r;
}*/

multiset<int> z; // -beneficios (i,j]

int doit(vector<pair<pair<int,int>,int> >& w, int t){
	int r=0;
	int i=0,j=w.size()-1;
	z.clear();
	fore(i,1,w.size())z.insert(-w[i].fst.snd);
	while(i<j){
		while(j>i&&w[i].fst.fst+w[j].fst.fst>t){
			z.erase(z.find(-w[j].fst.snd));
			j--;
		}
		if(j==i)break;
		r=max(r,w[i].fst.snd-*z.begin());
		i++;
		if(i<j)z.erase(z.find(-w[i].fst.snd));
	}
	return r;
}

int main(){
	scanf("%d%d%d",&n,&c,&d);
	fore(i,0,n){
		int b,p;char s[8];
		scanf("%d%d%s",&b,&p,s);
		if(s[0]=='C')wc.pb(mp(mp(p,b),i));
		else wd.pb(mp(mp(p,b),i));
	}
	sort(wc.begin(),wc.end());sort(wd.begin(),wd.end());
	wc2=wc;wd2=wd;
	fore(i,1,wc.size())wc[i].fst.snd=max(wc[i].fst.snd,wc[i-1].fst.snd);
	fore(i,1,wd.size())wd[i].fst.snd=max(wd[i].fst.snd,wd[i-1].fst.snd);
	int r=0;
	r=max(r,doit(wc2,c));r=max(r,doit(wd2,d));
	int k=0;
	while(k<wc.size()&&wc[k].fst.fst<=c)k++;
	k--;
	int asd=0;
	bool v=true;
	if(k>=0)asd+=wc[k].fst.snd;
	else v=false;
	k=0;
	while(k<wd.size()&&wd[k].fst.fst<=d)k++;
	k--;
	if(k>=0)asd+=wd[k].fst.snd;
	else v=false;
	//printf(" %d %d\n",r,asd);
	if(v)r=max(r,asd);
	printf("%d\n",r);
	return 0;
}