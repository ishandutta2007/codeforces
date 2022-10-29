#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n,m,k,x,s;
int a[200005];
int c[200005];
pair<int,int> w[200005];

int main(){
	scanf("%d%d%d%d%d",&n,&m,&k,&x,&s);
	fore(i,0,m)scanf("%d",a+i);
	fore(i,0,m)scanf("%d",c+i);
	a[m]=x;
	c[m++]=0;
	fore(i,0,k)scanf("%d",&w[i].snd),w[i].snd=-w[i].snd;
	fore(i,0,k)scanf("%d",&w[i].fst);
	sort(w,w+k);
	fore(i,0,k)w[i].snd=-w[i].snd;
	fore(i,1,k)w[i].snd=max(w[i].snd,w[i-1].snd);
	unsigned long long r=-1;
	fore(i,0,m){
		if(c[i]>s)continue;
		int j=lower_bound(w,w+k,mp(s-c[i]+1,-1))-w-1;
		if(j<0)r=min(r,(unsigned long long)1LL*n*a[i]);
		else {
			//printf("%d\n",w[j].snd);
			r=min(r,(unsigned long long)1LL*max(n-w[j].snd,0)*a[i]);
		}
	}
	cout<<r<<endl;
	return 0;
}