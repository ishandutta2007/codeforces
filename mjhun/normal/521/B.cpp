#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000009
using namespace std;

typedef long long ll;

int n;
map<pair<int,int>,int > id;
int x[100005];
int y[100005];
int q[100005];
int w[100005];
bool a[100005];
priority_queue<int> q1;
priority_queue<int> q2;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d%d",x+i,y+i);
		id[mp(x[i],y[i])]=i;
	}
	fore(i,0,n){
		fore(l,-1,2)q[i]+=id.count(mp(x[i]+l,y[i]-1));
	}
	fore(i,0,n){
		fore(l,-1,2)w[i]+=id.count(mp(x[i]+l,y[i]+1))&&q[id[mp(x[i]+l,y[i]+1)]]==1;
		if(!w[i])q1.push(i),q2.push(-i);
	}
	int t=0,r=0;
	int _=0;
	while(_<n){
		int k;
		if(!t)k=q1.top(),q1.pop();
		else k=-q2.top(),q2.pop();
		if(a[k]||w[k])continue;
		_++;
		a[k]=true;id.erase(mp(x[k],y[k]));
		if(q[k]==1){
			fore(l,-1,2)if(id.count(mp(x[k]+l,y[k]-1))){
				int j=id[mp(x[k]+l,y[k]-1)];
				w[j]--;
				if(!w[j])q1.push(j),q2.push(-j);
			}
		}
		fore(l,-1,2)if(id.count(mp(x[k]+l,y[k]+1))){
			int j=id[mp(x[k]+l,y[k]+1)];
			q[j]--;
			if(q[j]==1){
				fore(l,-1,2)if(id.count(mp(x[j]+l,y[j]-1))){
					int i=id[mp(x[j]+l,y[j]-1)];
					w[i]++;
				}
			}
		}
		r=(1LL*r*n+k)%MOD;
		t^=1;
	}
	printf("%d\n",r);
	return 0;
}