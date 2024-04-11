#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n;
bool a[100005];
int x[100005];
int f[100005];
queue<pair<int,int> > q;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d",x+i);
		f[i]=i+1;
	}
	x[n]=n+1;
	for(int i=n-2;i>=0;--i){
		if(x[i]>x[i+1])q.push(mp(i,1));
	}
	memset(a,true,sizeof(a));
	int r=0;
	while(!q.empty()){
		int k=q.front().fst,t=q.front().snd;q.pop();
		if(!a[k])continue;
		r=t;
		a[f[k]]=false;
		f[k]=f[f[k]];
		if(x[k]>x[f[k]])q.push(mp(k,t+1));
	}
	printf("%d\n",r);
	return 0;
}