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
	int num[n];
	char c;
	fore(i,0,n){
		cin>>c; num[i]=1+c-'1';
	}
	
	int sum=0;
	fore(i,0,n) sum+=num[i];
	
	if(sum==0){cout<<"YES";}else{
		fore(i,2,sum+1){
			if(sum%i==0){
				int parc=0;
				fore(j,0,n){
					parc+=num[j];
					if(parc==sum/i){parc=0;
					}else if(parc>sum/i){break;	
					}
					
				}
				
				if(parc==0){cout<<"YES"; return 0;
				}
			}
		}
		
		cout<<"NO";
		
	}
	
	return 0;
}