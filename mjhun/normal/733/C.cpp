#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

void perdi(){puts("NO");exit(0);}

ll a[512];
ll b[512];
int n,m;
vector<pair<int,char> > sol;

void d(int k){
	fore(i,k+1,n){
		a[i-1]=a[i];
	}
	n--;
}

int main(){
	scanf("%d",&n);
	ll ss=0;
	fore(i,0,n)scanf("%lld",a+i),ss+=a[i];
	scanf("%d",&m);
	fore(i,0,m)scanf("%lld",b+i),ss-=b[i];
	if(ss)perdi();
	while(1){
		int i=0;
		while(i<n&&a[i]==b[i])i++;
		if(i==n)break;
		ll s=0;
		int j=i;
		while(s<b[i]){
			s+=a[j++];
		}
		if(s>b[i])perdi();
		ll m=-1;
		fore(k,i,j)m=max(m,a[k]);
		int p=-1;
		fore(k,i,j){
			if(a[k]==m){
				if((k-1>=i&&a[k-1]<a[k])||(k+1<j&&a[k+1]<a[k])){
					p=k;
					break;
				}
			}
		}
		if(p<0)perdi();
		if(p-1>=i&&a[p-1]<a[p]){
			sol.pb(mp(p+1,'L'));
			a[p]+=a[p-1];
			d(p-1);
		}
		else {
			sol.pb(mp(p+1,'R'));
			a[p]+=a[p+1];
			d(p+1);
		}
	}
	puts("YES");
	fore(i,0,sol.size()){
		printf("%d %c\n",sol[i].fst,sol[i].snd);
	}
	return 0;
}