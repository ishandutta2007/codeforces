#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define snd second
#define fst first
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define INF (1LL<<60)
using namespace std;
typedef long long ll;

ll h;int n,m,k;
ll a[100005];int c[100005];
bool v[100005];
set<pair<int,int> > w;
vector<ll> s;
ll d[100005];
priority_queue<pair<ll,int> > q;

int main(){
	scanf("%lld%d%d%d",&h,&n,&m,&k);
	fore(i,0,n)scanf("%lld%d",a+i,c+i),a[i]--;
	fore(i,0,n)if(a[i]%k==0)v[i]=true,w.insert(mp(-c[i],i));
	while(m--){
		int t;
		scanf("%d",&t);
		if(t==1){
			ll asd;scanf("%lld",&asd);s.pb(asd);
			fore(i,1,k)d[i]=INF;
			q.push(mp(0,0));
			while(!q.empty()){
				auto p=q.top();q.pop();
				int x=p.snd;
				if(d[x]!=-p.fst)continue;
				for(auto c:s){
					int y=(x+c)%k;
					if(d[x]+c<d[y]){
						d[y]=d[x]+c;
						q.push(mp(-d[y],y));
					}
				}
			}
			fore(i,0,n)if(!v[i]&&d[a[i]%k]<=a[i]){
				v[i]=true;
				w.insert(mp(-c[i],i));
			}
		}
		else if(t==2){
			int x,y;
			scanf("%d%d",&x,&y);x--;
			if(v[x]){assert(w.count(mp(-c[x],x)));w.erase(mp(-c[x],x));}
			c[x]-=y;
			if(v[x])w.insert(mp(-c[x],x));
		}
		else {
			if(w.empty())puts("0");
			else {
				printf("%d\n",-w.begin()->fst);
				w.erase(w.begin());
			}
		}
	}
	return 0;
}