#include <bits/stdc++.h>
using namespace std;

int n;
int lo[10],hi[10];

int main(){
	cin >> n;	
	for (int i=0; i<n; i++) cin >> lo[i] >> hi[i];
	double ans = 0.0;
	for (int i=0; i<n; i++)
		for (int j=1; j<=hi[i]; j++){
			double p = 1.0/(hi[i]-lo[i]+1.0);
			double q = 1.0/(hi[i]-lo[i]+1.0);
			for (int k=0; k<n; k++) if (k != i){
				p = p * (j-(k<i)<lo[k] ? 0.0 : (min(j-(k<i),hi[k])-lo[k]+1.0)/(hi[k]-lo[k]+1.0));
				q = q * (j-1<lo[k] ? 0.0 : (min(j-1,hi[k])-lo[k]+1.0)/(hi[k]-lo[k]+1.0));
			}
			if (j>=lo[i])
				ans+= (p-q) * j;
			p = (hi[i]-max(lo[i],j+1)+1)/(hi[i]-lo[i]+1.0);
			q = p;
			for (int k=0; k<n; k++) if (k != i){
				p = p * (j<lo[k] ? 0.0 : (min(j,hi[k])-lo[k]+1.0)/(hi[k]-lo[k]+1.0));
				q = q * (j-1<lo[k] ? 0.0 : (min(j-1,hi[k])-lo[k]+1.0)/(hi[k]-lo[k]+1.0));
			}
			ans+= (p-q) * j;
		}
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}