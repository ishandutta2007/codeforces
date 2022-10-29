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
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

set<int> xs;
map<int,int> id;int nid;
int n,m;
int a[100005],h[100005],l[100005],r[100005],b[10005],z[10005];
double w[1<<20];
int s[1<<20];

int main(){
	scanf("%d%d",&n,&m);
	fore(i,0,n)scanf("%d%d%d%d",a+i,h+i,l+i,r+i),l[i]=100-l[i],r[i]=100-r[i],xs.insert(a[i]-h[i]),xs.insert(a[i]),xs.insert(a[i]+1),xs.insert(a[i]+h[i]+1);
	fore(i,0,m)scanf("%d%d",b+i,z+i),xs.insert(b[i]);
	for(int x:xs)id[x]=nid++;
	fore(i,0,n){
		if(l[i]){
			w[id[a[i]-h[i]]]+=log(1.*l[i]/100);
			w[id[a[i]]]-=log(1.*l[i]/100);
		}
		else {
			s[id[a[i]-h[i]]]++;
			s[id[a[i]]]--;
		}
		if(r[i]){
			w[id[a[i]+1]]+=log(1.*r[i]/100);
			w[id[a[i]+h[i]+1]]-=log(1.*r[i]/100);
		}
		else {
			s[id[a[i]+1]]++;
			s[id[a[i]+h[i]+1]]--;
		}
	}
	fore(i,1,nid)w[i]+=w[i-1],s[i]+=s[i-1];
	double rr=0.;
	fore(i,0,m)if(!s[id[b[i]]])rr+=exp(w[id[b[i]]])*z[i];
	assert(!isnan(rr));
	printf("%.12lf\n",rr);
	return 0;
}