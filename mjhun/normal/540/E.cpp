#include <algorithm>
#include <cstdio>
#include <map>
#define mp make_pair
#define fst first
#define snd second
using namespace std;

int n;
map<int,int> w;
pair<int,int> q[200005];
int v[200005];
int vt[200005];

long long f(int a,int b){
	if(b-a<2)return 0;
	int m=(a+b)/2;
	int l1=m-a,i1,i2;
	long long r=f(a,m)+f(m,b);
	for(int i=a;i<m;++i){
		vt[i]=v[i];
	}
	i1=a;i2=m;
	for(int i=a;i<b;++i){
		if(i1==m||(i2<b&&v[i2]<vt[i1])){
			r+=l1-(i1-a);
			v[i]=v[i2++];
		}
		else {
			v[i]=vt[i1++];
		}
	}
	return r;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int a,b,t;
		scanf("%d%d",&a,&b);
		if(!w[a])w[a]=a;
		if(!w[b])w[b]=b;
		t=w[a];w[a]=w[b];w[b]=t;
	}
	int k=0;
	for(map<int,int>::iterator it=w.begin();it!=w.end();++it){
		q[k]=mp(it->fst,it->snd);
		v[k]=it->snd;
		++k;
	}
	long long r=0;
	for(int i=0;i<k;++i){
		if(q[i].snd>q[i].fst){
			r+=q[i].snd-q[i].fst-(lower_bound(q+i,q+k,mp(q[i].snd,0))-(q+i));
		}
		else if(q[i].snd<q[i].fst){
			r+=q[i].fst-q[i].snd-((q+i)-lower_bound(q,q+i,mp(q[i].snd,0)));
		}
	}
	r+=f(0,k);
	printf("%I64d\n",r);
	return 0;
}