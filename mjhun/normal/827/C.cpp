#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

struct FT {
	vector<int> ft;int n;
	FT(int n):n(n),ft(n+1){}
	FT(){}
	void upd(int i0, int v){
		for(int i=i0+1;i<=n;i+=i&-i)ft[i]+=v;
	}
	int get(int i0){
		int r=0;
		for(int i=i0;i;i-=i&-i)r+=ft[i];
		return r;
	}
	int get(int i0, int i1){
		return get(i1)-get(i0);
	}
};

FT f[16][16][4];
int id[256];
char s[100005];

int main(){
	id['A']=0;
	id['C']=1;
	id['G']=2;
	id['T']=3;
	scanf("%s",s);
	fore(k,1,11){
		fore(i,0,k)fore(l,0,4)f[k][i][l]=FT(200105/k);
		for(int i=0;s[i];++i){
			f[k][i%k][id[s[i]]].upd(i/k,1);
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int i;char ss[4];
			scanf("%d%s",&i,ss);i--;
			fore(k,1,11)f[k][i%k][id[s[i]]].upd(i/k,-1);
			s[i]=ss[0];
			fore(k,1,11)f[k][i%k][id[s[i]]].upd(i/k,1);
		}
		else {
			int s,e,k;char ss[16];
			scanf("%d%d%s",&s,&e,ss);s--;k=strlen(ss);
			int r=0;
			fore(i,0,k){
				int j=(((i-s)%k)+k)%k;
				int a=(s-i+k-1)/k,b=(e-i+k-1)/k;
				r+=f[k][i][id[ss[j]]].get(a,b);
			}
			printf("%d\n",r);
		}
	}
	return 0;
}