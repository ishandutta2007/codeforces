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
	int n; cin>>n;
	int div[n],maxi=0;
	fore(i,0,n){cin>>div[i]; maxi=max(maxi,div[i]);}
	sort(div, div+n);
	cout<<div[n-1]<<" ";
	for(int i=n-2;i>=0;i--){
		if(div[n-1]%(div[i])!=0){
			cout<<div[i]; break;
		}else{
			if(div[i]==div[i+1]){
				cout<<div[i]; break;
			}
		}
	}
	
	return 0;
}