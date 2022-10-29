#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
using namespace std;
typedef long long ll;

int v[4];

int main(){
	fore(i,0,4)scanf("%d",v+i);
	sort(v,v+4);
	if(v[0]+v[1]>v[2]||v[1]+v[2]>v[3])puts("TRIANGLE");
	else if(v[0]+v[1]==v[2]||v[1]+v[2]==v[3])puts("SEGMENT");
	else puts("IMPOSSIBLE");
	return 0;
}