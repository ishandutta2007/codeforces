#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

vector<int> a;
vector<int> w[300005];
bool v[300005];
int n,q;

int main(){
	scanf("%d%d",&n,&q);
	int mt=0,r=0;
	fore(i,0,q){
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1){
			w[x].pb(a.size());
			a.pb(x);
			r++;
		}
		else if(t==2){
			fore(j,0,w[x].size()){
				if(!v[w[x][j]]){
					v[w[x][j]]=true;
					r--;
				}
			}
			w[x].clear();
		}
		else {
			fore(j,mt,x){
				if(!v[j]){
					v[j]=true;
					r--;
				}
			}
			mt=max(mt,x);
		}
		printf("%d\n",r);
	}
	return 0;
}