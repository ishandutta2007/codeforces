#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

void go(vector<pair<long long,int>> &a){
	a.insert(a.begin(),make_pair(0LL,-1));
	rep(i,a.size()-1){
		a[i+1].first += a[i].first;
	}
}

int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<pair<long long,int>> AB,A,B;
	
	rep(i,n){
		long long a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		if(b&&c)AB.emplace_back(a,i);
		else if(b)B.emplace_back(a,i);
		else if(c)A.emplace_back(a,i);
	}
	
	sort(AB.begin(),AB.end());
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
	go(AB);
	go(A);
	go(B);
	//cout<<AB.size()<<','<<B.size()<<','<<A.size()<<endl;
	if((int)AB.size() + min((int)A.size(),(int)B.size()) - 2 < k){
		cout<<-1<<endl;
		return 0;
	}
	
	long long ans = Inf;
	int m = min((int)A.size(),(int)B.size())-1;
	rep(i,AB.size()){
		int x = k-i;
		if(x<0)continue;
		if(x>m)continue;
	//	cout<<i<<','<<x<<endl;
		long long temp = AB[i].first + A[x].first + B[x].first;
		ans = min(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}