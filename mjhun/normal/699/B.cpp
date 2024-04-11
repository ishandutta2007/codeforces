#include <bits/stdc++.h>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

int n,m;
char b[1024][1024];
int r[1024];
int c[1024];


int main(){
	scanf("%d%d",&n,&m);
	int q=0;
	for(int i=0;i<n;++i){
		scanf("%s",b[i]);
		for(int j=0;j<m;++j){
			if(b[i][j]=='*'){
				r[i]++;
				c[j]++;
				q++;
			}
		}
	}

	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(r[i]+c[j]-(b[i][j]=='*')==q){
				printf("YES\n%d %d\n",i+1,j+1);
				return 0;
			}
		}
	}
	puts("NO");
	/*
	bool w=true;
	int ri=-1,rj=-1;
	int ni=0;nj=0;
	for(int i=0;i<n;++i){
		if(r[i])ni++;
		if(r[i]>1){
			if(ri<0)ri=i;
			else w=false;
		}
	}
	for(int j=0;j<m;++j){
		if(c[i])nj++;
		if(c[i]>1){
			if(rj<0)rj=j;
			else w=false;
		}
	}
	if(!w){puts("NO");return 0;}
	if((ri>=0&&r[ri]<nj)||(rj>=0&&c[rj]<ni)){puts("NO");return 0;}
*/	return 0;
}