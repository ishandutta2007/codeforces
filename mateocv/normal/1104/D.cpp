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
	string s;
	char llega;
	while(1){
		cin>>s;
		if(s=="mistake"||s=="end") break;
		cout<<"? 0 1"<<endl;
		cin>>llega;
		if(llega=='x'){cout<<"! 1"<<endl;
		}else{
			cout<<"? 1 2"<<endl;
			cin>>llega;
			if(llega=='x'){cout<<"! 2"<<endl;
			}else{int i=1;
				while(1){
					if(i<29){cout<<"? "<<(1<<i)<<" "<<(1<<(i+1))<<endl;}else{cout<<"? "<<(1<<i)<<" "<<(1000000000)<<endl;
					}
					cin>>llega;
					if(llega=='x') break; else i++;
				}
				int l=(1<<i),r,mid;
				if(i<29){r=(1<<(i+1));}else{r=1000000000;}
				while(1){
				  mid=(l+r)/2;
				  cout<<"? "<<l<<" "<<mid<<endl;
				  cin>>llega;
				  if(llega=='x'){
				     r=mid;
				  }else l=mid;
				  if(r==l+1)break;
				  if(r==l)break;
}
				cout<<"! "<<r<<endl;
		}
		}
		
	}
	
	return 0;
}