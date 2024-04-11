#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int v;
int x[16];

int main(){
	scanf("%d",&v);
	int m=1<<20;
	fore(i,0,9)scanf("%d",x+i),m=min(m,x[i]);
	if(m>v){puts("-1");return 0;}
	int d=v/m;
	while(d){
		for(int i=8;i>=0;--i){
			if(x[i]<=v&&(v-x[i])/m==d-1){
				v-=x[i];
				putchar('1'+i);
				break;
			}
		}
		d--;
	}
	puts("");
	return 0;
}