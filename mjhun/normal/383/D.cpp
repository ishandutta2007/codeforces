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
#define MOD 1000000007
#define O 5005
using namespace std;
typedef long long ll;

inline void add(int& a, int b){
	a+=b;
	if(a>=MOD)a-=MOD;
}

int w0[10015],s0[10015],w1[10015],s1[10015];
int n,a[1024];
int r;

void doit(int s, int e){
	if(s+1==e)return;
	int m=(s+e)/2;
	mset(s0,0);mset(w0,0);w0[O]=1;
	int t=0;
	for(int i=m-1;i>=s;--i){
		mset(w1,0);
		fore(j,max(O-t,0),min(O+t+1,10015)){
			if(j-a[i]>=0){
				add(w1[j-a[i]],w0[j]);
				add(s0[j-a[i]],w0[j]);
				//w1[j-a[i]]+=w0[j];w1[j-a[i]]%=MOD;
				//s0[j-a[i]]+=w0[j];s0[j-a[i]]%=MOD;
			}
			if(j+a[i]<10015){
				add(w1[j+a[i]],w0[j]);
				add(s0[j+a[i]],w0[j]);
				//w1[j+a[i]]+=w0[j];w1[j+a[i]]%=MOD;
				//s0[j+a[i]]+=w0[j];s0[j+a[i]]%=MOD;
			}
		}
		t+=a[i];
		mcpy(w0,w1);
	}
	mset(s1,0);mset(w0,0);w0[O]=1;
	t=0;
	fore(i,m,e){
		mset(w1,0);
		fore(j,max(O-t,0),min(O+t+1,10015)){
			if(j-a[i]>=0){
				add(w1[j-a[i]],w0[j]);
				add(s1[j-a[i]],w0[j]);
				//w1[j-a[i]]+=w0[j];w1[j-a[i]]%=MOD;
				//s1[j-a[i]]+=w0[j];s1[j-a[i]]%=MOD;
			}
			if(j+a[i]<10015){
				add(w1[j+a[i]],w0[j]);
				add(s1[j+a[i]],w0[j]);
				//w1[j+a[i]]+=w0[j];w1[j+a[i]]%=MOD;
				//s1[j+a[i]]+=w0[j];s1[j+a[i]]%=MOD;
			}
		}
		t+=a[i];
		mcpy(w0,w1);
	}
	//printf(" asd %d %d\n",w0[O-2],w1[O+2]);
	fore(i,0,O){
		add(r,1LL*s0[i]*s1[2*O-i]%MOD);
		add(r,1LL*s1[i]*s0[2*O-i]%MOD);
		//r+=1LL*s0[i]*s1[2*O-i]%MOD;r%=MOD;
		//r+=1LL*s1[i]*s0[2*O-i]%MOD;r%=MOD;
		//if(1LL*s0[i]*s1[2*O-i]%MOD||1LL*s1[i]*s0[2*O-i]%MOD)printf(" %d %d\n",i-O,r);
	}
	//r+=1LL*s0[O]*s1[O]%MOD;r%=MOD;
	add(r,1LL*s0[O]*s1[O]%MOD);
	//printf("%d %d %d\n",s,e,r);
	//doit(s,m);doit(m,e);
	doit(m,e);doit(s,m);
}


int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	doit(0,n);
	printf("%d\n",r);
	return 0;
}