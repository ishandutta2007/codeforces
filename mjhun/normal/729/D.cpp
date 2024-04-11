#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int n,a,b,k;
char s[200005];
vector<int> x,r;

int main(){
	scanf("%d%d%d%d%s",&n,&a,&b,&k,s);
	x.pb(-1);
	fore(i,0,n)if(s[i]-'0')x.pb(i);
	x.pb(n);
	fore(i,0,x.size()-1){
		k=x[i]+b;
		while(k<x[i+1])r.pb(k),k+=b;
	}
	fore(i,1,a)r.pop_back();
	printf("%d\n",(int)r.size());
	fore(i,0,r.size()){
		if(i)putchar(' ');
		printf("%d",r[i]+1);
	}
	puts("");
	return 0;
}