#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
typedef pair<int,int> P;

const int N=100100;
const int L=18;
int a[N];
int mn[N][L];
int mx[N][L];
P w[N];
LL ans[N];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	F(i,0,n-1){
		cin>>a[i];
		mn[i][0]=a[i];
		mx[i][0]=a[i];
		w[i]=P(a[i],i);
	}
	F(i,1,L-1){
		F(j,0,n-1){
			mn[j][i]=min(mn[j][i-1],mn[(j+(1<<(i-1)))%n][i-1]);
			mx[j][i]=max(mx[j][i-1],mx[(j+(1<<(i-1)))%n][i-1]);
			// cerr<<"mx "<<j<<" "<<i<<" "<<mx[j][i]<<endl;
		}
	}
	if(mn[0][L-1]*2>=mx[0][L-1]){
		memset(ans,-1,sizeof(ans));
	}
	else{
		sort(w,w+n);
		reverse(w,w+n);
		F(ii,0,n-1){
			int i=w[ii].second;
			int x=i;
			int da=0;
			for(int j=L-1;j>=0;j--){
				bool b1=mn[x][j]*2<a[i];
				bool b2=mx[x][j]>a[i];
				if(!b1&&!b2){
					x+=(1<<j);
					x%=n;
					da+=(1<<j);
				}
			}
			// cerr<<i<<" "<<x<<endl;
			ans[i]=da+(a[x]>a[i]?ans[x]:0);
		}
	}
	F(i,0,n-1)cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}