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

int n,k,N=5010;
int a[5010];

/*int buscar(int x){
	int suma=0;
	fore(i,0,n){if(a[i]==x){suma++;
	}
	}
	
	return suma;
}*/

int main(){
	
	cin>>n>>k;
	memset(a,0,sizeof a);
	int cant[5010],maxim=0;
	memset(cant,0,sizeof cant);
	fore(i,0,n){cin>>a[i];cant[a[i]-1]++;/*cout<<cant[a[i]-1]<<" ";*/if(cant[a[i]-1]>maxim){maxim=cant[a[i]-1];
	}
	}
//	cout<<maxim<<endl;
	
	/*fore(i,0,n){cant[i]=buscar(i+1); if(cant[i]>maxim){maxim=cant[i];
	}
	}*/
	
	if(maxim>k){cout<<"NO";
	}else{cout<<"YES"<<endl;
		 int van[5010],sol[n],maxc=1;
		 //memset(van,0,sizeof van);
		 fore(i,0,5010){van[i]=cant[i];
		 }
		 fore(i,0,n){sol[i]=cant[a[i]-1]-van[a[i]-1]+1; if(sol[i]>maxc){maxc=sol[i];
		 }
		 van[a[i]-1]--;
		 }
	


		if(maxc<k){
			int jf=0,rein=0;
			while(maxc<k){
				fore(j,jf+1,n){
					fore(i,0,n){
						if((j!=i)&&(sol[j]==sol[i])){sol[j]=maxc+1;jf=j;rein++;break;
						}
					}
					if(rein){rein=0;break;
					}
					
				}
				maxc++;
			}
		}
		
		fore(i,0,n){cout<<sol[i]<<" ";
		}
	}
	
	return 0;
}