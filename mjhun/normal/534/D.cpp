#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n;
vector<int> w[200005];
vector<int> r;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		w[x].pb(i);
	}
	int k=0;
	while(k>=0){
		if(w[k].empty())k-=3;
		else {
			r.pb(w[k].back());
			w[k].pop_back();
			k++;
		}
	}
	if(r.size()<n)puts("Impossible");
	else {
		puts("Possible");
		fore(i,0,n){
			if(i)putchar(' ');
			printf("%d",r[i]+1);
		}
		puts("");
	}
	return 0;
}