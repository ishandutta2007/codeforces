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

int a[7],k;

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d",&k);
		fore(i,0,7)scanf("%d",a+i);
		int r=1<<30;
		fore(i,0,7){ // empiezo en i
			int j=i,s=0;
			while(j<7&&s<k)s+=a[j++];
			if(s==k)r=min(r,j-i);
			else {
				int rr=7-i;
				int q=0;
				fore(j,0,7)q+=a[j];
				rr+=(k-s-1)/q*7;
				int rem=k-s-(k-s-1)/q*q;
				int j=0;
				while(j<7&&rem)rem-=a[j++],rr++;
				j=0;
				while(j<7&&rem)rem-=a[j++],rr++;
				r=min(r,rr);
			}
		}
		printf("%d\n",r);
	}
	return 0;
}