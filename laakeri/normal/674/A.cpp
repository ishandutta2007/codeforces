#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int c[5050];
int a[5050];
int vv[5050];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int ii=1;ii<=n;ii++){
			c[ii]=0;
		}
		int v=1;
		for (int ii=i;ii<n;ii++){
			c[a[ii]]++;
			if (c[a[ii]]>c[v]){
				v=a[ii];
			}
			else if(c[a[ii]]==c[v]&&a[ii]<v){
				v=a[ii];
			}
			vv[v]++;
		}
	}
	for (int i=1;i<=n;i++){
		cout<<vv[i]<<" ";
	}
	cout<<endl;
}