#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
vector<pair<int,int> > s;
vector<pair<int,int> > t;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x,a;
		scanf("%d%d",&x,&a);
		if(x<0)s.pb(mp(-x,a));
		else t.pb(mp(x,a));
	}
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	int r=0;
	if(s.size()>t.size())swap(s,t);
	for(auto p:s)r+=p.snd;
	fore(i,0,min(s.size()+1,t.size()))r+=t[i].snd;
	printf("%d\n",r);
	return 0;
}