#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

vector<vector<int> > r;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=n-1;i>=4;i-=2){
		r.pb({i-2,i-1,i});r.pb({i-2,i-1,i});
		fore(j,0,i-2)r.pb({i,j,i-1,(j+1)%(i-2)});
	}
	if(n%2)r.pb({0,1,2}),r.pb({0,1,2});
	else r.pb({0,1,2}),r.pb({1,2,3}),r.pb({2,3,0}),r.pb({3,0,1});
	printf("%d\n",(int)r.size());
	for(auto v:r){
		printf("%d",(int)v.size());
		for(int x:v)printf(" %d",x+1);
		puts("");
	}
	return 0;
}