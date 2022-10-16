#include <iostream>
#include <cstdio>

#include <algorithm>

#include <vector>

#define repp(i,a,b,d) for(int i=a; i<=b; i+=d)
#define rep(i,a,b) repp(i,a,b,1)

#define pb push_back

using namespace std;

typedef long long ll;

vector<int> ans;

int main(){
	int n;
	cin>>n;
	int cnt = 0;
	rep(i,1,n){
		char c;
		cin>>c;
		if(c == 'B')cnt++;
		else if(c == 'W'){
			if(cnt > 0){
				ans.pb(cnt);
				cnt = 0;
			}
		}
	}
	if(cnt > 0)ans.pb(cnt);
	cout<<ans.size()<<endl;
	rep(i,0,(int)ans.size()-1)printf("%d ",ans[i]);
	printf("\n");
	return 0;
}