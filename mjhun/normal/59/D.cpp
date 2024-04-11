#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int g[100005][4];
int p[300005];
int n,k;
vector<int> sol;
vector<int> t;
set<int> w;

int main(){
	scanf("%d",&n);
	fore(i,0,3*n){
		int x;
		scanf("%d",&x);
		p[x]=i;
	}
	fore(i,0,n)fore(j,0,3){
		scanf("%d",&g[i][j]);
	}
	scanf("%d",&k);
	fore(i,0,n){
		fore(j,0,3)w.insert(g[i][j]);
		if(w.find(k)!=w.end()){
			if(p[g[i][0]]<p[k]||p[g[i][1]]<p[k]||p[g[i][2]]<p[k]){
				fore(j,1,3*n+1){
					if(j!=k)sol.pb(j);
				}
			}
			else {
				int f=-1;
				fore(j,0,3)if(g[i][j]!=k)f=max(f,g[i][j]);
				fore(j,1,3*n+1){
					if(w.find(j)==w.end())t.pb(j);
				}
				w.erase(k);
				for(set<int>::iterator it=w.begin();it!=w.end();++it){
					if(*it<=f)sol.pb(*it);
					else t.pb(*it);
				}
				sort(t.begin(),t.end());
				fore(j,0,t.size())sol.pb(t[j]);
			}
			break;
		}
	}
	printf("%d",sol[0]);
	fore(i,1,sol.size())printf(" %d",sol[i]);
	puts("");
	return 0;
}