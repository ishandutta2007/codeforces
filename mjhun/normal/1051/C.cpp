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
int x[128];
bool asd[128];
map<int,int> c;
int q=0;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i),c[x[i]]++;
	for(auto p:c)q+=p.snd==1;
	if(q%2==0){
		puts("YES");
		int a=0,b=0;
		for(auto p:c){
			if(p.snd==1){asd[p.fst]=a;a^=1;}
			else {asd[p.fst]=b;b^=1;}
		}
		fore(i,0,n)putchar(asd[x[i]]?'A':'B');
		puts("");
	}
	else {
		int t=-1;
		for(auto p:c)if(p.snd>=3)t=p.fst;
		if(t<0){puts("NO");}
		else {
			puts("YES");
			int a=0,b=0;
			for(auto p:c){
				if(p.snd==1){asd[p.fst]=a;a^=1;}
				else {asd[p.fst]=b;b^=1;}
			}
			bool qwe=false;
			fore(i,0,n){
				if(x[i]==t){
					putchar(qwe?'B':'A');
					qwe=true;
				}
				else putchar(asd[x[i]]?'A':'B');
			}
			puts("");
		}
	}
	return 0;
}