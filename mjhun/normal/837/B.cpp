#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

char b[128][128],b2[128][128];
int n,m;

bool doit(){
	if(n%3)return false;
	char c0=b[0][0],c1=b[n/3][0],c2=b[2*n/3][0];
	if(c0==c1||c0==c2||c1==c2)return false;
	fore(i,0,n/3)fore(j,0,m){
		if(b[i][j]!=c0)return false;
		if(b[i+n/3][j]!=c1)return false;
		if(b[i+2*n/3][j]!=c2)return false;
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%s",b[i]);
	if(doit())puts("YES");
	else {
		fore(i,0,n)fore(j,0,m)b2[j][i]=b[i][j];
		memcpy(b,b2,sizeof(b));
		swap(n,m);
		if(doit())puts("YES");
		else puts("NO");
	}
	return 0;
}