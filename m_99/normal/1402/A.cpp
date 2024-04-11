#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000

int main(){
	
	long long n;
	cin>>n;
	
	
	
	vector<long long> remain(n,0LL);
	for(long long i=1;i<=n-1;i++){
		remain[(i*(n-1))%n] = i*(n-1);
	}
	
	vector<long long> a(n);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);

	if(n==1){
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		cout<<"1 1"<<endl;
		cout<<0<<endl;
		cout<<"1 1"<<endl;
		cout<<-a[0]<<endl;
		return 0;
	}
	
	
	cout<<1<<' '<<n-1<<endl;
	for(int i=0;i<n-1;i++){
		if(i!=0)printf(" ");
		long long t = a[i] + n*1000000000;
		t %= n;
		t = (n-t)%n;
		printf("%lld",remain[t]);
		a[i] += remain[t];
	}
	printf("\n");
	
	cout<<n<<' '<<n<<endl;
	long long x = (a.back()+n*1000000000)%n;

	cout<<-x<<endl;
	a.back()-=x;
	
	cout<<1<<' '<<n<<endl;
	for(int i=0;i<n;i++){
		if(i!=0)printf(" ");
		cout<<-a[i];
	}
	cout<<endl;
	
	return 0;
}