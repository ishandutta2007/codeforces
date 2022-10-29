#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int n,k;
vector<string> w[128];
string p;

int main(){
	cin>>n>>k;
	fore(i,0,n){
		string s;
		cin>>s;
		w[s.size()].pb(s);
	}
	cin>>p;
	int r=0;
	fore(i,0,p.size())r+=w[i].size();
	int r0=r+1;
	int r1=r+w[p.size()].size();
	r0+=(r0-1)/k*5;
	r1+=(r1-1)/k*5;
	printf("%d %d\n",r0,r1);
	return 0;
}