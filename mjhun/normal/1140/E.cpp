#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<b;++i)
#define pb push_back
#define SZ(x) ((int)(x).size())
#define MOD 998244353
using namespace std;

int add(int a, int b){
	a+=b;
	if(a>=MOD)a-=MOD;
	return a;
}
int mul(int a, int b){return 1LL*a*b%MOD;}
int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=mul(r,a);
		a=mul(a,a);
		e>>=1;
	}
	return r;
}

int n,k;
int f0[200005],f1[200005];

int doit(vector<int> v){
	n=SZ(v);
	int i=0,r=1;
	while(i<n){
		if(v[i]>0){
			if(i<n-1&&v[i]==v[i+1]){
				puts("0");
				exit(0);
			}
			i++;
			continue;
		}
		int j=i;
		while(j<n&&v[j]<0)j++;
		if(i&&j<n){
			if(v[i-1]==v[j])r=mul(r,f1[j-i]);
			else r=mul(r,f0[j-i]);
		}
		else if(i||j<n){
			r=mul(r,pm(k-1,j-i));
		}
		else {
			r=mul(r,mul(k,pm(k-1,j-i-1)));
		}
		i=j;
	}
	return r;
}

vector<int> a;
vector<int> b;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		if(i%2)a.pb(t);
		else b.pb(t);
	}
	f0[0]=1;
	f1[0]=0;
	fore(i,1,200005){
		f0[i]=add(mul(k-2,f0[i-1]),f1[i-1]);
		f1[i]=mul(k-1,f0[i-1]);
	}
	printf("%d\n",mul(doit(a),doit(b)));
	return 0;
}