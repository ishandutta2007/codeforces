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

int d0[19],d1[19];

void get(int* d){
	ll a;
	scanf("%lld",&a);
	fore(i,0,19)d[18-i]=a%10,a/=10;
}

int q[10];
int q2[10];
int r;

bool doit(){
	fore(i,0,19){
		if(d0[i]==d1[i]){
			if(!q[d0[i]])return false;
			q[d0[i]]--;
			continue;
		}
		assert(d0[i]<d1[i]);
		fore(j,d0[i]+1,d1[i])if(q[j])return true;
		if(q[d0[i]]){
			q[d0[i]]--;
			bool can=true;
			int k=9,w=0;
			fore(j,i+1,19){
				while(w==q[k])w=0,k--;
				if(d0[j]<k)break;
				if(d0[j]>k){can=false;break;}
				w++;
			}
			if(can)return true;
			q[d0[i]]++;
		}
		if(q[d1[i]]){
			q[d1[i]]--;
			bool can=true;
			int k=0,w=0;
			fore(j,i+1,19){
				while(w==q[k])w=0,k++;
				if(d1[j]>k)break;
				if(d1[j]<k){can=false;break;}
				w++;
			}
			if(can)return true;
		}
		return false;
	}
	return true;
}

void go(int k, int s){
	if(k==9){
		q[k]=s;
		fore(i,0,10)q2[i]=q[i];
		r+=doit();
		fore(i,0,10)q[i]=q2[i];
		return;
	}
	fore(i,0,s+1)q[k]=i,go(k+1,s-i);
}

int main(){
	get(d0);get(d1);
	go(0,19);
	printf("%d\n",r);
	return 0;
}