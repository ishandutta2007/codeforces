#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(i) for(int i=0;i<n;i++)
int c[100]={0};
int s(LL v){
	int ans=0;
	while(v>0){
		ans+=v%10;
		v/=10;
	}
	return ans;
}
int main(){
	LL n;
	cin>>n;
	LL ans=s(n);

	bool jw=false;
	while(n>0){
		int y=n%10;
		if(n>=10&&(y!=9||jw)){
			jw=true;
			ans+=9;
		}
		n/=10;
	}
	cout<<ans<<endl;
}