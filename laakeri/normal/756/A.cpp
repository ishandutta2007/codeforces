#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int p[202020];
int b[202020];
int u[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>p[i];
	int bs=0;
	for (int i=1;i<=n;i++) {
		cin>>b[i];
		bs+=b[i];
	}
	int v=(bs+1)%2;
	int c=0;
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			int x=i;
			while (u[x]==0){
				u[x]=1;
				x=p[x];
			}
			c++;
		}
	}
	if (c>1){
		v+=c;
	}
	cout<<v<<endl;
}