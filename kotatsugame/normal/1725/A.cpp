#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N,M;
	cin>>N>>M;
	cout<<(M==1?N-1:(long long)N*(M-1))<<endl;
}