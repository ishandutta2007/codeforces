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
	pair<int,int> somb[n];
	fore(i,0,n){
		cin>>somb[i].fst;
		somb[i].fst=n-somb[i].fst;
		somb[i].snd=i;
	}	
	
	sort(somb,somb+n);
	int van=0,er=0,guar=-1,vanguar;
	fore(i,0,n){
		if(guar==-1){
			guar=somb[i].fst;
			vanguar=guar;
			van++;
		}
		
		if(somb[i].fst==guar){somb[i].fst=van; vanguar--;
		}else{er++; break;
		}
		
		
		if(vanguar==0){
			guar=-1;
		}
		
		if(i==n-1&&guar!=-1)er++;
		
	}
	
	if(er){cout<<"Impossible";
	}else{cout<<"Possible\n";
		fore(i,0,n){swap(somb[i].fst,somb[i].snd);
		}
		sort(somb,somb+n);
		fore(i,0,n) cout<<somb[i].snd<<" ";
	}
	
	
	
	return 0;
}