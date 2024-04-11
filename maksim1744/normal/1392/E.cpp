#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e2+60;
int n, q, m;
int Iwannabethegay[N][N];
signed main() {
	cin>>n;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) cout<<(Iwannabethegay[i][j]=((j-1)&1?1ll<<(n*2-i-j):0))<<' ', fflush(stdout);
		cout<<endl;
		fflush(stdout);
	}
	cin>>q;
	for(int i=1; i<=q; ++i) {
		cin>>m;
		int Left=1, Right=1, Karry=m;
		while(Left^n||Right^n) {
			cout<<Left<<' '<<Right<<endl;
			fflush(stdout);
			if(Left==n) ++Right;
			else {
				if(Right==n) ++Left;
				else{
					if((Right-1)&1) Karry>=Iwannabethegay[Left+1][Right]?Karry-=Iwannabethegay[Left+1][Right], Left++:++Right;
					else Karry>=Iwannabethegay[Left][Right+1]?Karry-=Iwannabethegay[Left][Right+1], Right++:++Left;
				}
			}
		}
		cout<<n<<' '<<n<<endl;
		fflush(stdout);
	}
	return 0;
}