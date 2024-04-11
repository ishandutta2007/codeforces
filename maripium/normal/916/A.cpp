#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
bool lucky(int x){
	int h=x/60;
	int m=x%60;
	return (h%10==7||m%10==7);
	}
signed main()
{
int x, h, m;
cin>>x>>h>>m;
int cur=60*h+m;
//int ans1,ans2;
for(int i=0;i<=1440;i++){
	if(lucky((cur+1440-i*x)%1440)){
		cout<<i;return 0;
	}
}
}