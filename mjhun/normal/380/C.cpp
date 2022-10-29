#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

struct node {
	int r,n0,n1;
};

void merge(node &s0, node &s1, node &t){
	int r,n0,n1;
	r=s0.r+s1.r+2*min(s0.n0,s1.n1);
	n0=s0.n0-min(s0.n0,s1.n1)+s1.n0;
	n1=s1.n1-min(s0.n0,s1.n1)+s0.n1;
	t.r=r;t.n0=n0;t.n1=n1;
}

char t[1<<20];
int n;
node st[1<<22];

void st_init(int k, int s, int e){
	if(s+1==e){
		st[k].r=0;
		if(t[s]=='(')st[k].n0=1,st[k].n1=0;
		else st[k].n0=0,st[k].n1=1;
		return;
	}
	int m=(s+e)/2;
	st_init(2*k,s,m);
	st_init(2*k+1,m,e);
	merge(st[2*k],st[2*k+1],st[k]);
}

void st_query(int k, int s, int e, int a, int b, node &r){
	if(e<=a||s>=b)return;
	if(s>=a&&e<=b){merge(r,st[k],r);return;}
	int m=(s+e)/2;
	st_query(2*k,s,m,a,b,r);
	st_query(2*k+1,m,e,a,b,r);
}

int main(){
	scanf("%s",t);n=strlen(t);
	st_init(1,0,n);
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);a--;
		node r;r.r=r.n0=r.n1=0;
		st_query(1,0,n,a,b,r);
		printf("%d\n",r.r);
	}
	return 0;
}