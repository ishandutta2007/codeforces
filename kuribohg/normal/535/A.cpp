#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const string A[]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
const string B[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
const string C[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
int n;
int main()
{
	cin>>n;
	if(n<10) {cout<<B[n]<<endl;return 0;}
	if(n/10==1) {cout<<C[n%10]<<endl;return 0;}
	cout<<A[n/10];
	if(n%10==0) {cout<<endl;return 0;}
	cout<<"-"<<B[n%10]<<endl;
	return 0;
}