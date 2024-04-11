#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

char s[64][128];
int n,m;

int doit(int l){
	int r=l;
	fore(i,1,n){
		int k=0;
		while(k<m&&strncmp(s[0]+l,s[i]+k,m))k++;
		if(k==m)return 1<<30;
		r+=k;
	}
	return r;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%s",s[i]);
	m=strlen(s[0]);
	fore(i,0,n)fore(j,0,m)s[i][m+j]=s[i][j];
	int r=1<<30;
	fore(i,0,m){
		r=min(r,doit(i));
		if(r==(1<<30))break;
	}
	if(r==(1<<30))r=-1;
	printf("%d\n",r);
	return 0;
}