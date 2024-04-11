#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n,a,b,kk;
char s[200005];
vector<pair<int,int> > w;  // length, start
vector<int> sol;

int main(){
	scanf("%d%d%d%d%s",&n,&a,&b,&kk,s);
	s[n++]='1';kk++;
	int l=0;
	fore(i,0,n){
		if(s[i]=='1'){
			w.pb(mp(i-l,l));
			l=i+1;
		}
	}
	sort(w.begin(),w.end());
	int q=0;
	fore(i,0,w.size()){
		q+=w[i].fst/b;
	}
	int i=0;
	while(q>=a){
		if(w[i].fst<b)i++;
		else {
			sol.pb(w[i].snd+b-1);
			w[i].snd+=b;
			w[i].fst-=b;
			q--;
		}
	}
	printf("%d\n",sol.size());
	fore(i,0,sol.size()){
		if(i)putchar(' ');
		printf("%d",sol[i]+1);
	}
	puts("");
	return 0;
}