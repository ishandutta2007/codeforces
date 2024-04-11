#include <bits/stdc++.h>
using namespace std;
#define int long long
//whatwhathwhathwhthwhatthwathklfjklsdfjsjdlfjsdfjsldkfjlksdjflksdf
//i swear to god if this acs
signed main(){
	int a[9];
	for(int i=0;i<9;i++)cin>>a[i];
	int ans=4e18;
	for(int i=0;i<=a[0];i++){
		int go=((a[3]+i-1)/a[3])*a[5],no=(a[0]-i)*a[2]+a[4]*i;
		if(no>a[1]&&a[2]>a[7]){
			int nxt=(((no+a[2]-a[1]-a[7]-1)/(a[2]-a[7]))+a[6]-1)/a[6];
			if(a[6]*nxt>a[0]-i)continue;
			ans=min(ans,go+nxt*a[8]);
		}
		else if(a[1]>=no)ans=min(ans,go);
	}
	for(int i=0;i<=a[0];i++){
		//toggle by 3, because other plan
		int go=((a[6]+i-1)/a[6])*a[8],no=(a[0]-i)*a[2]+a[7]*i;
		if(no>a[1]&&a[2]>a[4]){
			int nxt=(((no+a[2]-a[1]-a[4]-1)/(a[2]-a[4]))+a[3]-1)/a[3];
			if(a[3]*nxt>a[0]-i)continue;
			ans=min(ans,go+nxt*a[5]);
		}
		else if(a[1]>=no)ans=min(ans,go);
	}
	cout<<(ans==4e18?-1:ans)<<"\n"; // forgot
}