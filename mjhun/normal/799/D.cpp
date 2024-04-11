#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int a,b,h,w,n;
int x[100005];
map<pair<int,int>,int> d;
queue<pair<int,int> > q;

int main(){
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	fore(i,0,n)scanf("%d",x+i);
	sort(x,x+n);reverse(x,x+n);
	if(max(a,b)<=max(h,w)&&min(a,b)<=min(h,w)){puts("0");return 0;}
	auto p=mp((a+h-1)/h,(b+w-1)/w);
	if(p.fst>p.snd)swap(p.fst,p.snd);
	d[p]=0;
	q.push(p);
	p=mp((a+w-1)/w,(b+h-1)/h);
	if(p.fst>p.snd)swap(p.fst,p.snd);
	if(!d.count(p))d[p]=0,q.push(p);
	while(!q.empty()){
		auto p=q.front();q.pop();
		int h=p.fst,w=p.snd,k=d[p];
		if(k==n)break;
		int hh=(h+x[k]-1)/x[k],ww=w;
		if(hh>ww)swap(hh,ww);
		if(hh==1&&ww==1){printf("%d\n",k+1);return 0;}
		if(!d.count(mp(hh,ww)))d[mp(hh,ww)]=k+1,q.push(mp(hh,ww));
		hh=h;ww=(w+x[k]-1)/x[k];
		if(hh>ww)swap(hh,ww);
		if(hh==1&&ww==1){printf("%d\n",k+1);return 0;}
		if(!d.count(mp(hh,ww)))d[mp(hh,ww)]=k+1,q.push(mp(hh,ww));
	}
	puts("-1");
	return 0;
}