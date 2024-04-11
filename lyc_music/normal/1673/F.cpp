#include<bits/stdc++.h>
using namespace std;
#define N 50
typedef long long ll;
int n,Q,a[N],b[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>Q;
	int tot=0;
	for(int i=1;i<n;++i){
		int lw=__lg(i&(-i));
		a[i]=1<<(lw*2);
		tot+=a[i]*n;
	}
	for(int j=1;j<n;++j){
		int lw=__lg(j&(-j));
		b[j]=1<<(lw*2+1);
		tot+=b[j]*n;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<n;++j){
			cout<<b[j]<<' ';
		}
		cout<<'\n';
	}
	for(int i=1;i<n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i]<<' ';
		}
		cout<<'\n';
	}
	cout.flush();
//	cerr<<" tot: "<<tot<<endl;
	int X=1,Y=1;
	auto check=[&](int sx,int sy,int tx,int ty,int C)->bool{
		int X1=min(sx,tx),X2=max(sx,tx);
		int Y1=min(sy,ty),Y2=max(sy,ty);
		for(int i=X1;i<X2;++i){
			C^=a[i];
		}
		for(int j=Y1;j<Y2;++j){
			C^=b[j];
		}
		return C==0;
	};
	auto work=[&](int C)->void{
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(check(X,Y,i,j,C)){
					X=i,Y=j;
					cout<<i<<' '<<j<<endl;
					return;
				}
			}
		}
	};
	while(Q--){
		int C;
		cin>>C;
		work(C);
	}
	return 0;
}