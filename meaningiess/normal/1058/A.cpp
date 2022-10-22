#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i,x;cin>>n;
    for (i=1;i<=n;i++) {cin>>x;if (x) {puts("HARD");return 0;}}
    puts("EASY");
}