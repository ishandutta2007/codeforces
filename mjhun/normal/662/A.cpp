#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define M 60
using namespace std;

typedef long long ll;

//bitset<500005> x[64];
char x[64][500005];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	ll d=0;
	fore(i,0,n){
		ll a,b,c;
		cin>>a>>b;
		d^=b;
		c=a^b;
		fore(j,0,M)x[j][i]=(c>>j)&1;
	}
	fore(j,0,M)x[j][n]=(d>>j)&1;
	int i=0,j=0;
	while(i<M&&j<n){
		if(!x[i][j]){
			fore(i0,i+1,M){
				if(x[i0][j]){
					fore(j0,j,n+1){
						//int s=x[i][j0];
						//x[i][j0]=x[i0][j0];
						//x[i0][j0]=s;
						swap(x[i][j0],x[i0][j0]);
					}
					break;
				}
			}
		}
		if(x[i][j]){
			fore(i0,i+1,M){
				if(x[i0][j]){
					fore(j0,j,n+1){
						//x[i0][j0]=x[i0][j0]^x[i][j0];
						x[i0][j0]^=x[i][j0];
					}
				}
			}
			i++;
		}
		j++;
	}
	int m=M;
	fore(i,0,M){
		bool w=true;
		fore(j,0,n){
			if(x[i][j]){w=false;break;}
		}
		if(w){
			if(x[i][n]){m=-1;break;}
			else m--;
		}
	}
	if(m<0)cout<<"1/1"<<endl;
	else cout<<(1LL<<m)-1<<'/'<<(1LL<<m)<<endl;
	return 0;
}