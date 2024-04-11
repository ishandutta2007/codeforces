#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,m;
pair<int,int> s[200005];
set<pair<int,int> > p;
int r0[200005];
int r1[200005];
int nc,na;

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		p.insert(mp(x,i));
	}
	fore(i,0,m){
		int x;
		scanf("%d",&x);
		s[i]=mp(x,i);
	}
	sort(s,s+m);
	fore(i,0,m){
		int x=s[i].fst;
		int k=0,f=-1;
		while(1){
			set<pair<int,int> >::iterator it=p.lower_bound(mp(x,-1));
			if(it==p.end()||it->fst!=x){
				if(x==1)break;
				else {
					x=(x+1)/2;
					k++;
				}
			}
			else {
				f=it->snd;
				break;
			}
		}
		if(f>=0){
			p.erase(mp(x,f));
			nc++;na+=k;
			r0[s[i].snd]=k;
			r1[f]=s[i].snd+1;
		}
	}
	printf("%d %d\n",nc,na);
	fore(i,0,m){
		if(i)putchar(' ');
		printf("%d",r0[i]);
	}
	puts("");
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r1[i]);
	}
	puts("");
	return 0;
}