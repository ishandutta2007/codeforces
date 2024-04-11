#include <iostream>
#include <cstdio>

#include <algorithm>
#include <cstring>

#include <vector>
#include <string>

#define repp(i,a,b,d) for(int i=a; i<=b; i+=d)
#define rep(i,a,b) repp(i,a,b,1)

#define pb push_back

using namespace std;

typedef long long ll;

int arr[105];

int main(){
	int n,k;
	cin>>n>>k;
	rep(i,1,n){
		string str;
		cin>>str;
		arr[str.size()]++;
	}
	int q;
	string str;
	cin>>str;
	q = str.size();
	
	int best = 0,worst = 0;
	rep(i,1,100){
		if(i == q){
			best += 1;
			worst += arr[i];
			break;
		}
		best += arr[i];
		worst += arr[i];
	}
	
	best += ((best-1)/k)*5;
	worst += ((worst-1)/k)*5;
	
	printf("%d %d\n",best,worst);
	
	return 0;
}