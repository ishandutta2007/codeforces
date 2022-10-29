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
int a0[16],b0[16],a1[16],b1[16];
set<pair<int,int> > s0,s1;

pair<int,int> pr(int a, int b){
	if(a>b)swap(a,b);
	return mp(a,b);
}

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n){
		scanf("%d%d",a0+i,b0+i);
		if(a0[i]>b0[i])swap(a0[i],b0[i]);
		s0.insert({a0[i],b0[i]});
	}
	fore(i,0,m){
		scanf("%d%d",a1+i,b1+i);
		if(a1[i]>b1[i])swap(a1[i],b1[i]);
		s1.insert({a1[i],b1[i]});
	}
	int r=0;
	fore(k,1,10){
		bool c=false;
		fore(i,1,10)fore(j,1,10){
			if(k==i||k==j||i==j)continue;
			if(!s0.count(pr(k,i))||!s1.count(pr(k,j)))continue;
			c=true;
		}
		if(c){
			if(r==0)r=k;
			else r=-1;
		}
	}
	if(r<0){
		r=0;
		fore(k,1,10){
			fore(i,1,10)fore(j,1,10){
				if(k==i||k==j||i==j)continue;
				if(!s0.count(pr(k,i))||!s1.count(pr(k,j)))continue;
				fore(l,1,10)if(l!=k&&l!=i&&s1.count(pr(i,l)))r=-1;
				fore(l,1,10)if(l!=k&&l!=j&&s0.count(pr(j,l)))r=-1;
			}
		}
	}
	printf("%d\n",r);
	return 0;
}