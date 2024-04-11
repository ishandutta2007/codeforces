#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("-1");exit(0);}

int n,c;
vector<int> w[500005];
int s[1<<20];

void add(int a, int b){
	s[a]++;
	s[b]--;
}

int main(){
	scanf("%d%d",&n,&c);
	fore(i,0,n){
		int l;
		scanf("%d",&l);
		while(l--){
			int x;
			scanf("%d",&x);x--;
			w[i].pb(x);
		}
	}
	fore(i,0,n-1){
		int j=0;
		while(j<w[i].size()&&j<w[i+1].size()&&w[i][j]==w[i+1][j])j++;
		if(j==w[i].size())add(0,c);
		else {
			if(j==w[i+1].size())perdi();
			int x0=w[i][j],x1=w[i+1][j];
			if(x0<x1)add(0,c-x1),add(c-x0,c);
			else add(c-x0,c-x1);
		}
	}
	int p=0;
	fore(i,0,c){
		p+=s[i];
		if(p==n-1){printf("%d\n",i);return 0;}
	}
	puts("-1");
	return 0;
}