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

int p[10000005];
int x[100005];
set<int> s,a;
int n;

bool can(int k){
	a.clear();
	while(p[k]){
		a.insert(p[k]);
		k/=p[k];
	}
	a.insert(k);
	bool c=true;
	for(int k:a)if(s.count(k)){c=false;break;}
	return c;
}

int main(){
	for(int i=2;i<10005;++i)if(!p[i]){
		for(int j=i*i;j<10000005;j+=i)p[j]=i;
	}
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n){
		if(can(x[i])){
			for(int k:a)s.insert(k);
			continue;
		}
		else {
			int kk=x[i]+1;
			while(!can(kk))kk++;
			x[i]=kk;
			for(int k:a)s.insert(k);
			int t=2;
			fore(j,i+1,n){
				while(p[t]||s.count(t))t++;
				x[j]=t;
				t++;
			}
			break;
		}
	}
	fore(i,0,n)printf("%d%c",x[i]," \n"[i==n-1]);
	return 0;
}