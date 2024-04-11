#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,k,l;
bool e[128];

int main(){
	scanf("%d%d",&n,&k);
	memset(e,true,sizeof(e));
	int lh=0;
	fore(i,0,k){
		int a;
		scanf("%d",&a);
		a%=n-i;
		int h=lh;
		fore(j,0,a){
			while(!e[h])h++,h%=n;
			h++;h%=n;
		}
		while(!e[h])h++,h%=n;
		if(i)putchar(' ');
		printf("%d",h+1);
		e[h]=false;
		while(!e[h])h++,h%=n;
		lh=h;
	}
	puts("");
	return 0;
}