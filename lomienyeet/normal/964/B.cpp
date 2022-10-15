#include <bits/stdc++.h>
using namespace std;
int main(){
	int N,A,B,C,T;
	cin>>N>>A>>B>>C>>T;
	int arr[N];
	for(int i=0;i<N;i++)cin>>arr[i];
	sort(arr,arr+N);
	if(B>C)cout<<A*N<<"\n";
	else{
		int sum=A*N;
		int bruh=C-B;
		for(int i=0;i<N;i++){
			sum+=(T-arr[i])*bruh;
		}
		cout<<sum<<"\n";
	}
    return 0;
}