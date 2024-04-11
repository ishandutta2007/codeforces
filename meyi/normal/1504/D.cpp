#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int a,ans[maxn][maxn],n,x1=1,_y1_=1,x2=1,y2=2;
int main(){
	cin>>n;
	int cntb=n*n/2,cnta=n*n-cntb;
	while(cnta&&cntb){
		cin>>a;
		if(a!=1){
			ans[x1][_y1_]=1;
			cout<<"1 "<<x1<<" "<<_y1_<<endl;
			_y1_+=2;
			if(_y1_>n){
				++x1;
				_y1_-=n;
				if(n%2==0){
					if(_y1_==1)_y1_=2;
					else _y1_=1;
				}
			}
			--cnta;
		}
		else{
			ans[x2][y2]=2;
			cout<<"2 "<<x2<<" "<<y2<<endl;
			y2+=2;
			if(y2>n){
				++x2;
				y2-=n;
				if(n%2==0){
					if(y2==1)y2=2;
					else y2=1;
				}
			}
			--cntb;
		}
	}
	if(cntb){
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=n;++j)
				if(!ans[i][j]){
					cin>>a;
					ans[i][j]=(a==2?3:2);
					--cnta;
					cout<<(a==2?3:2)<<" "<<i<<" "<<j<<endl;
				}
	}
	else{
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=n;++j)
				if(!ans[i][j]){
					cin>>a;
					ans[i][j]=(a==1?3:1);
					--cntb;
					cout<<(a==1?3:1)<<" "<<i<<" "<<j<<endl;
				}
	}
	return 0;
}