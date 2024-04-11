#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){

	long long N,A,cf,cm,m;
	cin>>N>>A>>cf>>cm>>m;
	
	vector<pair<long long,int>> a(N);
	for(int i=0;i<N;i++){
		scanf("%lld",&a[i].first);
		a[i].second=i;
	}
	
	sort(a.begin(),a.end());
	
	vector<long long> Need(N+1,0);
	long long sum = 0;
	for(int i=0;i<=N;i++){
		if(i!=N){
			Need[i] = a[i].first * i - sum;
			sum += a[i].first;
		}
		else{
			Need[i] = A * i - sum;
		}
	}
	long long ans = a[0].first*cm;
	long long X = 0,Y = a[0].first;
	
	{
		int ind = distance(Need.begin(),upper_bound(Need.begin(),Need.end(),m));
		ind--;
		long long temp = 0;
		if(ind==N){
			temp = cf*N + cm*A;
			ans = temp;
			X = N;
			Y = A;
		}
		else{
			long long mm = m-Need[ind];
			long long mini = mm/(ind+1);
			mm = a[ind].first + mini;

			temp += mm * cm;
			if(temp>ans){
				ans = temp;
				X = 0;
				Y = mm;
			}
			
		}
	}
	
	for(int i=N-1;i>=0;i--){
		m -= A-a[i].first;
		if(m<0)break;
		long long temp = cf * (N-i);
		int ind = distance(Need.begin(),upper_bound(Need.begin(),Need.end(),m));
		ind--;
		
		if(ind==N){
			temp = cf*N + cm*A;
			ans = temp;
			X = N;
			Y = A;
			break;
		}
		else{
			ind = min(ind,i-1);
			if(ind<0)break;
			long long mm = m-Need[ind];
			long long mini = mm/(ind+1);
			mm = a[ind].first + mini;

			temp += mm * cm;
			if(temp>ans){
				ans = temp;
				X = N-i;
				Y = mm;
			}
			
		}
	}
	
	
	
	for(int i=0;i<X;i++){
		a[N-1-i].first = A;
	}
	for(int i=0;i<N;i++){
		if(a[i].first<Y)a[i].first=Y;
	}
	
	cout<<ans<<endl;
	vector<long long> Ans(N);
	for(int i=0;i<N;i++){
		Ans[a[i].second] = a[i].first;
	}
	
	for(int i=0;i<N;i++){
		if(i!=0)cout<<' ';
		cout<<Ans[i];
	}
	cout<<endl;
	
	return 0;
}