#include <bits/stdc++.h>
using namespace std;
char a[4];
int main(){
	a[0]='a';
	a[1]='a';
	a[2]='b';
	a[3]='b';
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
    	printf("%c",a[i%4]);
	}
return 0;
}