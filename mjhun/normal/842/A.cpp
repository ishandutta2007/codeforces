#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a;i<b;++i)

int main(){
	ll l,r,x,y,k;
	scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&y,&k);
	fore(i,x,y+1)if(k*i>=l&&k*i<=r){
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}