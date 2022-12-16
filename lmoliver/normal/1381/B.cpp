#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N=2010*2;
int a[N];
bool w[N];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(w,false,sizeof(w));
		w[0]=true;
		int sz=0;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		int mx=a[1];
		for(int i=1;i<=2*n;i++){
			sz++;
			if(i==2*n||a[i+1]>mx){
				// cerr<<i<<" "<<sz<<endl;
				for(int j=n-sz;j>=0;j--){
					w[j+sz]|=w[j];
				}
				sz=0;
				mx=a[i+1];
			}
		}
		// cerr<<n<<endl;
		cout<<(w[n]?"YES":"NO")<<endl;
	}
	return 0;
}