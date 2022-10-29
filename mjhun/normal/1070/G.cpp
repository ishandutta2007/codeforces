#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n,m;
int s[128],hh[128];
int w[128]; // cual heroe
int a[128];

void doit0(int k){ // k -> punto de encuentro
	vector<int> r0; // ultimo -> antes
	int h=-1;
	for(int i=n-1;i>=k;--i){
		if(!SZ(r0)&&w[i]<0)continue;
		if(!SZ(r0)){r0.pb(w[i]);h=hh[w[i]];continue;}
		if(w[i]>=0){
			r0.pb(w[i]);
			if(hh[w[i]]>h)h=hh[w[i]];
			else swap(r0[SZ(r0)-1],r0[SZ(r0)-2]);
		}
		else {
			h+=a[i];
			if(h<0)return;
		}
	}
	vector<int> r1;
	h=-1;
	fore(i,0,k+1){
		if(i==k&&SZ(r0))break;
		if(!SZ(r1)&&w[i]<0)continue;
		if(!SZ(r1)){r1.pb(w[i]);h=hh[w[i]];continue;}
		if(w[i]>=0){
			r1.pb(w[i]);
			if(hh[w[i]]>h)h=hh[w[i]];
			else swap(r1[SZ(r1)-1],r1[SZ(r1)-2]);
		}
		else {
			h+=a[i];
			if(h<0)return;
		}
	}
	printf("%d\n",k+1);
	bool p=false;
	while(!r0.empty()){
		if(p)putchar(' ');
		printf("%d",r0.back()+1);
		r0.pop_back();
		p=true;
	}
	while(!r1.empty()){
		if(p)putchar(' ');
		printf("%d",r1.back()+1);
		r1.pop_back();
		p=true;
	}
	puts("");
	exit(0);
}

void doit1(int k){ // k -> punto de encuentro
	vector<int> r1;
	int h=-1;
	fore(i,0,k+1){
		if(!SZ(r1)&&w[i]<0)continue;
		if(!SZ(r1)){r1.pb(w[i]);h=hh[w[i]];continue;}
		if(w[i]>=0){
			r1.pb(w[i]);
			if(hh[w[i]]>h)h=hh[w[i]];
			else swap(r1[SZ(r1)-1],r1[SZ(r1)-2]);
		}
		else {
			h+=a[i];
			if(h<0)return;
		}
	}
	vector<int> r0; // ultimo -> antes
	h=-1;
	for(int i=n-1;i>=k;--i){
		if(i==k&&SZ(r1))break;
		if(!SZ(r0)&&w[i]<0)continue;
		if(!SZ(r0)){r0.pb(w[i]);h=hh[w[i]];continue;}
		if(w[i]>=0){
			r0.pb(w[i]);
			if(hh[w[i]]>h)h=hh[w[i]];
			else swap(r0[SZ(r0)-1],r0[SZ(r0)-2]);
		}
		else {
			h+=a[i];
			if(h<0)return;
		}
	}
	printf("%d\n",k+1);
	bool p=false;
	while(!r1.empty()){
		if(p)putchar(' ');
		printf("%d",r1.back()+1);
		r1.pop_back();
		p=true;
	}
	while(!r0.empty()){
		if(p)putchar(' ');
		printf("%d",r0.back()+1);
		r0.pop_back();
		p=true;
	}
	puts("");
	exit(0);
}


int main(){
	mset(w,-1);
	scanf("%d%d",&n,&m);
	fore(i,0,m)scanf("%d%d",s+i,hh+i),s[i]--,w[s[i]]=i;
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n)doit0(i),doit1(i);
	puts("-1");
	return 0;
}