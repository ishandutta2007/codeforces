#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll lcm(ll a, ll b){
	return (a/__gcd(a, b))*b;
}
int u[111];
int a[111];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=1;
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			int x=i;
			int c=0;
			while (u[x]==0){
				u[x]=1;
				c++;
				x=a[x];
			}
			if (x==i){
				if (c>1){
					if (c%2==0){
						ans=lcm(ans, c/2);
					}
					else{
						ans=lcm(ans, c);
					}
				}
			}
			else{
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	cout<<ans<<endl;
}