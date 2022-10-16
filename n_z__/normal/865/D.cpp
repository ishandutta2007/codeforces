#include<bits/stdc++.h>
using namespace std;
#define int long long
priority_queue<int>q;
main(){
	int n,ans=0;
	cin>>n;
	while(n--){
        int a;
        cin>>a;
		ans+=a;
		q.push(-a);
        q.push(-a);
		ans+=q.top();
        q.pop();
	}
	cout<<ans<<endl;
}