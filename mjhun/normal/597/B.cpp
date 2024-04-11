#include <bits/stdc++.h>
using namespace std;

typedef struct {int r,l;} rl;
bool operator<(const rl& a, const rl& b){
	return a.r<b.r||(a.r==b.r&&a.l<b.l);
}

int n;
rl x[500005];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&x[i].l,&x[i].r);
	}
	sort(x,x+n);
	int w=-1,r=0;
	for(int i=0;i<n;++i){
		if(x[i].l>w){
			w=x[i].r;
			r++;
		}
	}
	printf("%d\n",r);
	return 0;
}