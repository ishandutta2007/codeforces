#include<bits/stdc++.h>
using namespace std;
#define i64 long long int 
int n;
vector<i64> a;
i64 calc(i64 n,i64 s){
	return s + (s-1)*n/2;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i*i<=n; i++)
		if(n%i==0){
			a.push_back(calc(n,i));
			if(i*i<n)a.push_back(calc(n,n/i));
		}
	sort(a.begin(),a.end());
	for(int i=0; i<a.size(); i++)
		cout << a[i] << (i+1 < a.size()?' ':'\n');
	return 0;
}