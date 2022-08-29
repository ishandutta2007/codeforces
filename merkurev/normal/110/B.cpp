#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	int n,i=0;
	cin>>n;
	while (i<n)
	{
		if (i%4==0) cout<<'a';
		if (i%4==1) cout<<'b';
		if (i%4==2)	cout<<'c';
		if (i%4==3) cout<<'d';
		i++;
	}
	return 0;
}