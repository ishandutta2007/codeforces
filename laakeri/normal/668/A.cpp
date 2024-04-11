#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int ma[111][111];
int val[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			ma[i][ii]=m*i+ii;
		}
	}
	for (int qq=0;qq<q;qq++){
		int t;
		cin>>t;
		if (t==1){
			vector<int> r(m);
			int a;
			cin>>a;
			a--;
			for (int i=0;i<m;i++){
				r[i]=ma[a][i];
			}
			for (int i=0;i<m;i++){
				ma[a][i]=r[(i+1)%m];
			}
		}
		else if(t==2){
			vector<int> c(n);
			int a;
			cin>>a;
			a--;
			for (int i=0;i<n;i++){
				c[i]=ma[i][a];
			}
			for (int i=0;i<n;i++){
				ma[i][a]=c[(i+1)%n];
			}
		}
		else{
			int r,c,x;
			cin>>r>>c>>x;
			r--;
			c--;
			val[ma[r][c]]=x;
		}
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			cout<<val[i*m+ii]<<" ";
		}
		cout<<'\n';
	}
}