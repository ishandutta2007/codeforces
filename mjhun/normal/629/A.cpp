#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;

typedef long long ll;

char b[128][128];
int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%s",b[i]);
	ll r=0;
	for(int i=0;i<n;++i){
		int s0=0,s1=0;
		for(int j=0;j<n;++j){
			if(b[i][j]=='C')s0++;
			if(b[j][i]=='C')s1++;
		}
		r+=(s0*(s0-1))/2;
		r+=(s1*(s1-1))/2;
	}
	cout<<r<<endl;
	return 0;
}