#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		if(a[n-2]>a[n-1]){
			cout<<-1<<endl;
			continue;
		}
		if(a.back() < 0){
			auto b = a;
			sort(b.begin(),b.end());
			if(a!=b)cout<<-1<<endl;
			else cout<<0<<endl;
			continue;
		}
		cout<<n-2<<endl;
		rep(i,n-2){
			printf("%d %d %d\n",i+1,n-1,n);
			//cout<<i+1<<' '<<n-1<<' '<<n<<endl;
		}
	}
	
	return 0;
}