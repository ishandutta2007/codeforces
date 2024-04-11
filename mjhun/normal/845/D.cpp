#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int n;

int main(){
#ifdef DEMETRIO
	freopen("din","r",stdin);
#endif
	while(scanf("%d",&n)!=EOF){
		int r=0,q=0,v;stack<int> s;
		fore(i,0,n){
			int t;
			scanf("%d",&t);
			if(t==1){
				scanf("%d",&v);
				while(!s.empty()&&v>s.top()){
					r++;s.pop();
				}
			}
			else if(t==2){
				r+=q;q=0;
			}
			else if(t==3){
				int x;
				scanf("%d",&x);
				if(v>x)r++;
				else s.push(x);
			}
			else if(t==4){
				q=0;
			}
			else if(t==5){
				while(!s.empty())s.pop();
			}
			else {
				q++;
			}
		}
		printf("%d\n",r);
		puts("");
	}
	return 0;
}