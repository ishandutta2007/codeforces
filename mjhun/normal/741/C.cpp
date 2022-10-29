#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n;
int a[100005];
int b[100005];
int g[200005];
bool c[200005];

bool ready(){
	fore(i,0,n)if(c[a[i]]==c[b[i]])return false;
	return true;
}

void doit(int a, int b){
	int j=a^1;
	c[a]^=1;
	c[j]^=1;
	if(c[j]==c[g[j]])doit(g[j],j);
}

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d%d",a+i,b+i);a[i]--;b[i]--;
		g[a[i]]=b[i];
		g[b[i]]=a[i];
	}
	fore(i,0,2*n)c[i]=i%2;
	while(!ready()){
		fore(i,0,n)if(c[a[i]]==c[b[i]]){
			doit(a[i],b[i]);
		}
	}
	fore(i,0,n){
		printf("%d %d\n",c[a[i]]+1,c[b[i]]+1);
	}
	return 0;
}