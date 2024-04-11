#include <bits/stdc++.h>
using namespace std;
 
//GG
 
int main() {
	int T; cin>>T;
	while(T--) {
		int w,h; cin>>w>>h;
		int xa,xb,ya,yb; cin>>xa>>ya>>xb>>yb;
		int z,x; cin>>z>>x;
		int mini = 1e9;
		//Move in x direction
		if(xb-xa+z <= w) {
			mini = min(mini,min(z-xa,xb+z-w));
			//cout<<z<<' '<<xb<<' '<<w<<' '<<xa<<endl;
		}
		if(yb-ya+x <= h) {
			mini = min(mini,min(x-ya,yb+x-h));
		}
		
		if(mini == 1e9) {
			cout<<"-1\n";
		}
		else {
			if(mini < 0)
				mini = 0;
			double d = 1.0*mini;
			printf("%.10f ",d);
		}
	}
	return 0;
}