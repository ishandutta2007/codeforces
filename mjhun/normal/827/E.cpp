#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<int> d[500005];
int n;
char s[500005];
set<int> r;
set<int> xv,xk;

int main(){
	for(int i=1;i<500005;++i)for(int j=i;j<500005;j+=i)d[j].pb(i);
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%s",&n,s);
		r.clear();xv.clear();xk.clear();
		fore(i,0,n){
			if(i)r.insert(i);
			if(s[i]=='K'){
				if(r.size()<xv.size()){
					vector<int> z;
					for(int a:r)if(s[i-a]=='V'){
						for(int w:d[a])z.pb(w);
					}
					for(int w:z)r.erase(w);
				}
				else {
					for(int j:xv)if(r.count(i-j)){
						int a=i-j;
						for(int w:d[a])r.erase(w);
					}
				}
				xk.insert(i);
			}
			else if(s[i]=='V'){
				if(r.size()<xk.size()){
					vector<int> z;
					for(int a:r)if(s[i-a]=='K'){
						for(int w:d[a])z.pb(w);
					}
					for(int w:z)r.erase(w);
				}
				else {
					for(int j:xk)if(r.count(i-j)){
						int a=i-j;
						for(int w:d[a])r.erase(w);
					}
				}
				xv.insert(i);
			}
		}
		r.insert(n);
		printf("%d\n",(int)r.size());
		for(int x:r)printf("%d ",x);puts("");
	}
	return 0;
}