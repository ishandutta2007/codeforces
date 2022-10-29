#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

char b[128];
int q[8];
int n,m,k;

int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(m==1){puts("Second");return 0;}
	bool g0=false,g1=false;
	fore(_,0,n){
		scanf("%s",b);
		int j0=0;
		while(j0<m&&b[j0]=='-')j0++;
		if(j0==m)continue;
		int j1=j0+1;
		while(j1<m&&b[j1]=='-')j1++;
		if(j1==m){
			if(b[j0]=='G')g0=true;
			else g1=true;
		}
		else {
			if(b[j0]==b[j1]){
				if(m>2){
					if(b[j0]=='G')g0=true;
					else g1=true;
				}
			}
			else {
				fore(i,0,8)q[i]+=((j1-j0-1)>>i)&1;
			}
		}
	}
	if(g0&&g1)puts("Draw");
	else if(g0)puts("First");
	else if(g1)puts("Second");
	else {
		g0=false;
		fore(i,0,8)if(q[i]%(k+1))g0=true;
		if(g0)puts("First");
		else puts("Second");
	}
	return 0;
}