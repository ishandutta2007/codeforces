#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int s,k;
vector<int> r;
vector<int> f;

int main(){
	scanf("%d%d",&s,&k);
	f.pb(1);
	while(f.back()<s){
		int a=0;
		fore(i,max((int)f.size()-k,0),f.size())a+=f[i];
		f.pb(a);
	}
	for(int i=f.size()-1;i>=0;--i)if(f[i]<=s){s-=f[i];r.pb(f[i]);}
	printf("%d\n0",(int)r.size()+1);
	for(int x:r)printf(" %d",x);
	puts("");
	return 0;
}