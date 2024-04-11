#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k; cin>>n>>k;
	map<char,int> van;
	fore(i,0,26){
		van['a'+i]=0;
	}
	char curr='A',llega;
	int prog=0;
	
	fore(i,0,n){
		cin>>llega;
		if(llega==curr){
			prog++;
			if(prog==k){
				van[curr]++;
				prog=0;
			}
		}else{
			curr=llega;
			prog=1;
			if(k==1){
				van[curr]++;
				prog=0;
			}
		}
	}
	
	int maxi=0;
	fore(i,0,26){
		maxi=max(van['a'+i],maxi);
	}
	cout<<maxi;
	
	return 0;
}